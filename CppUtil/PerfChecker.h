#include <vector>
#include <windows.h>
#include <assert.h>

class PerfChecker
{
public:
    enum TimeUnit : UINT
    {
        Second = 0,
        MilliSecond,
        MicroSecond,
    };

public:
    PerfChecker()
        : _timeunit(Second),
        _isRun(false) { Initialize(); }
    PerfChecker(TimeUnit timeunit)
        : _timeunit(timeunit),
        _isRun(false) { Initialize(); }

    ~PerfChecker() {}

    // Commands
    bool Start();
    bool Check();
    bool End();
    bool GetPerformTime(std::vector<double>& perform_time, bool accumulate = false);
    bool GetTotalPerformTime(double& perform_time);

    // Util
    void SetUnit(const TimeUnit unit) { _timeunit = unit; }

private:
    // Calculate
    double CalcPerformTime(const LONGLONG& start, const LONGLONG& end);
    double GetUnitFactor();

    void Initialize() { _check.clear(); }
    bool CheckValidity();

private:
    // data
    std::vector<LONGLONG> _check;

    // setting
    TimeUnit _timeunit;
    bool _isRun;

    // etc
    LARGE_INTEGER _dummy;
};
