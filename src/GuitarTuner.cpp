#include "include/SignalProcessing.hpp"
#include "include/MicProcessingAndSpectrumAnalyser.hpp"
#include "include/GuitarTuner.hpp"

void guitar_tuner(){
    get_audio_input();
    while(true){
        std::vector<double> raw_data = get_audio_data();
        for (int i = 0; i < raw_data.size(); i++){
            std::cout << raw_data[i] << std::endl;
        }
    }

}