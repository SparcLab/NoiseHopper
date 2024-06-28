# NoiseHopper

In this work, we have proposed an improved covert channel to exfiltrate data from air-gapped devices, formed by pulse width modulation (PWM) controlled electromagnetic emission with spectrum covertness rendered by frequency hopping. It is covert not only in the execution domain (malicious code) but also in the RF spectrum (it looks like noise or spurious peaks have been added to the existing RF spectrum), making it difficult to detect. Our proposed channel can penetrate through a wall and we have transmitted MNIST dataset images (at a 10 kbps rate) using the covert channel to show its efficacy.

The sample Arduino code file is provided here. For more details on the implementation, please read our paper and watch the hardware demo. Also, we have used the FastPwmPin library to generate a PWM signal. Links for our paper, demo, and this library are given below.

# Citation (IEEE Format)
If you use our work and/or code, please cite our paper as:
* M. F. Bari and S. Sen, "NoiseHopper: Emission Hopping Air-Gap Covert Side Channel with Lower Probability of Detection," 2024 IEEE International Symposium on Hardware Oriented Security and Trust (HOST), Tysons Corner, VA, USA, 2024, pp. 21-32, doi: 10.1109/HOST55342.2024.10545402. 

# Download The Paper

* Link1: https://ieeexplore.ieee.org/abstract/document/10545402

* Link2: https://www.researchgate.net/publication/381234280_NoiseHopper_Emission_Hopping_Air-Gap_Covert_Side_Channel_with_Lower_Probability_of_Detection

# Demo Video

[![YouTube](http://i.ytimg.com/vi/v8LqhLB0fwU/hqdefault.jpg)](https://www.youtube.com/watch?v=v8LqhLB0fwU)

# FastPwmPin Library
 We have used the 'FastPwmPin' Arduino library to generate a fast PWM signal on pin 10 of Arduino UNO. You need to download this library and keep it in your project folder to run our code successfully.
Link: https://github.com/maxint-rd/FastPwmPin
