#include "include/SignalProcessing.hpp"
#include "include/MicProcessingAndSpectrumAnalyser.hpp"
#include "include/GuitarTuner.hpp"

void guitar_tuner(){
    get_audio_input();
    make_window();
    while(true){
        std::vector<double> raw_data = get_audio_data();
        harmonic_product_spectrum(raw_data);
        update_window(raw_data, SAMPLE_SIZE);
    }

}