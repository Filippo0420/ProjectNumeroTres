#include <iostream>
#include <matplot/matplot.h>
#include <pybind11/pybind11.h>

const int M_PI = 3.14;
namespace plt = matplot;
int add(int i, int j) {
    return i + j;
}
void process_audio(const std::vector<short>& samples) {
    plt::plot(samples, "*");
    plt::show();
}
void plotSignal(std::vector<double> signal) {
    plt::plot(signal);
    plt::xlabel("Samples");
    plt::ylabel("Amplitude");
    plt::title("Sinusoidal Signal");
    plt::grid(true);
    plt::show();
}
std::vector<double> generateWave(std::string WaveType, int frequency, double duration, double samplingFrequency) {
    std::vector<double>;
    if (WaveType == "sin")
    {
        int numSamples = duration * samplingFrequency;
        std::vector<double> signal(numSamples);
        for (int i = 0; i < numSamples; ++i) {
            double t = static_cast<double>(i) / samplingFrequency;
            signal[i] = sin(2 * M_PI * frequency * t);
        }
        plotSignal(signal);
    }
    else if (WaveType == "cos") {
        int numSamples = duration * samplingFrequency;
        std::vector<double> signal(numSamples);
        for (int i = 0; i < numSamples; ++i) {
            double t = static_cast<double>(i) / samplingFrequency;
            signal[i] = cos(2.0 * M_PI * frequency * t);
        }
        plotSignal(signal);
    }
    else if (WaveType == "pwm") {
        int numSamples = duration * samplingFrequency;
        std::vector<double> signal(numSamples);
        double period = 1.0 / frequency;
        double halfPeriod = period / 2.0;
        for (int i = 0; i < numSamples; ++i) {
            double t = static_cast<double>(i) / samplingFrequency;
            double remainder = fmod(t, period);
            if (remainder < halfPeriod) {
                signal[i] = 1.0;
            }
            else {
                signal[i] = -1.0;
            }
        }
        plotSignal(signal);
    }
    else if (WaveType == "sawtooth") {
        int numSamples = duration * samplingFrequency;
        std::vector<double> signal(numSamples);
        double period = 1.0 / frequency;
        for (int i = 0; i < numSamples; ++i) {
            double t = static_cast<double>(i) / samplingFrequency;
            signal[i] = 2.0 * (t / period - floor(0.5 + t / period));
        }
        plotSignal(signal);
    }
}

PYBIND11_MODULE(pybind_cpp, m) {
	m.doc() = "pybind11 example plugin";

    m.def("add", &add, "adding function");
    m.def("process_audio", &process_audio, "adding process_audio");
    m.def("generateWave", &generateWave, "generate wave function", pybind11::arg("WaveType"), pybind11::arg("frequency"), pybind11::arg("duration"), pybind11::arg("samplingFrequency"));

}