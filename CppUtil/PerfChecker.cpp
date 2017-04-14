#include <algorithm>
#include <assert.h>

#include "PerfChecker.h"
#include <xutility>

const double MEGA = 1.0e+6;

bool PerfChecker::Start()
{
    if (_isRun) { /*already running*/ assert(0); return false; }
    Initialize();
    _isRun = true;
    // start count
    if (!QueryPerformanceCounter(&_dummy)) { assert(0); return false; }
    _check.push_back(_dummy.QuadPart);
    return true;
}

bool PerfChecker::Check()
{
    if (!_isRun) { /*do no running*/ assert(0); return false; }
    if (!QueryPerformanceCounter(&_dummy)) { assert(0); return false; }
    _check.push_back(_dummy.QuadPart);
    return true;
}

bool PerfChecker::End()
{
    if (!_isRun) { /*do no running*/ assert(0); return false; }
    if (!QueryPerformanceCounter(&_dummy)) { assert(0); return false; }
    _check.push_back(_dummy.QuadPart);
    _isRun = false;
    return true;
}

bool PerfChecker::GetPerformTime(std::vector<double>& perform_time, bool accumulate /*= false*/)
{
    if (!CheckValidity()) { return false; }
    perform_time.clear();

    double accum_perftime = 0.0;
    for (unsigned int i = 1; i < _check.size(); ++i)
    {
        const double unit_perftime = CalcPerformTime(_check[i - 1], _check[i]);
        if (accumulate)
        {
            accum_perftime += unit_perftime;
        }
        perform_time.push_back(unit_perftime);
    }
    return true;
}

bool PerfChecker::GetTotalPerformTime(double& perform_time)
{
    if (!CheckValidity()) { return false; }
    perform_time = CalcPerformTime(*_check.begin(), *(--_check.end()));
    return true;
}

double PerfChecker::CalcPerformTime(const LONGLONG& start, const LONGLONG& end)
{
    if (!QueryPerformanceFrequency(&_dummy)) { assert(0); return 0.0; }
    const double us = (end - start) * MEGA / static_cast<double>(_dummy.QuadPart); // micro second
    return  us * GetUnitFactor();
}

double PerfChecker::GetUnitFactor()
{
    switch (_timeunit)
    {
    case PerfChecker::Second:      return 1.0e-6;
    case PerfChecker::MilliSecond: return 1.0e-3;
    case PerfChecker::MicroSecond: return 1.0;
    default: assert(0); break;
    }

    return 0.0;
}

bool PerfChecker::CheckValidity()
{
    if (_isRun || _check.empty()) { assert(0); return false; }
    return true;
}