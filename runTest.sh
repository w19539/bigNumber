g++ -o bigPowerTest bigNum.cpp bigNum.h bigPower.cpp bigPower.h bigPowerTest.cpp -lboost_unit_test_framework
./bigPowerTest --log_level=test_suite
