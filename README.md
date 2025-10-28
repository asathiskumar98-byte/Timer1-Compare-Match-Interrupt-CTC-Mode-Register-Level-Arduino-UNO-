🧭 AVR Timer1 – Output Compare Mode (Toggle)

Microcontroller: ATmega328P
IDE/Compiler: Arduino IDE / AVR-GCC
Timer Mode: Output Compare (Toggle on Match)
Pin Used: PB1 (OC1A)

⚙️ Project Description

This project demonstrates how to use Timer1 in Output Compare Mode to toggle OC1A (PB1) each time the timer matches a predefined value in the OCR1A register.

With a prescaler of 1024 and OCR1A = 15625, the toggle frequency corresponds to a 1 Hz square wave (since it toggles every 1 second — full cycle = 2 seconds).

🧮 Frequency Calculation

CPU Clock (f<sub>CPU</sub>) = 16 MHz
Prescaler (N) = 1024
Compare Value (OCR1A) = 15625

𝑓
𝑡
𝑜
𝑔
𝑔
𝑙
𝑒
=
𝑓
𝐶
𝑃
𝑈
2
×
𝑁
×
(
𝑂
𝐶
𝑅
1
𝐴
+
1
)
=
16
,
000
,
000
2
×
1024
×
15626
≈
0.5
 Hz
f
toggle
	​

=
2×N×(OCR1A+1)
f
CPU
	​

	​

=
2×1024×15626
16,000,000
	​

≈0.5 Hz

Since toggle happens twice per cycle, Output Frequency = 0.5 Hz → Period = 2 seconds (1 s HIGH, 1 s LOW).

🧰 Hardware Setup
Pin	Function	Description
PB1	OC1A	Output compare toggle pin
GND	Ground	Common reference
VCC	+5 V	Power supply

Connect an LED (with a 330 Ω resistor) to PB1 → You’ll see it blink at 1 Hz.

🧩 Applications

Generating precise square waves or timing signals

Controlling clocks and real-time events

Synchronizing with external circuits or PWM drivers
