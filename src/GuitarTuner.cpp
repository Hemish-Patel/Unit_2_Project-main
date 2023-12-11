#include "include/SignalProcessing.hpp"
#include "include/MicProcessingAndSpectrumAnalyser.hpp"
#include "include/GuitarTuner.hpp"

#include <thread> // Include the <thread> header

void guitar_tuner(){
    get_audio_input();
    make_window();
    while(true){
        std::vector<double> raw_data = get_audio_data();
        std::vector<double> displaythis = harmonic_product_spectrum(raw_data);
        update_window(displaythis, SAMPLE_SIZE);
        
        std::this_thread::sleep_for(std::chrono::milliseconds(10)); // Sleep for 10 milliseconds
    }
}