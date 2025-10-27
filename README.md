⚡ Timer1 Compare Match Interrupt (CTC Mode) — Register-Level (Arduino UNO)

This project demonstrates Timer1 Output Compare Match Interrupt (CTC Mode) using register-level programming on the ATmega328P (Arduino UNO).
When the timer value matches the compare register OCR1A, the OC1A (D9) pin toggles automatically to generate a precise square wave.

⚙️ Hardware Used

Arduino UNO (ATmega328P)

LED connected to pin D9 (OC1A)

220Ω current-limiting resistor

🔌 Pin Configuration
Component	Function	Arduino Pin	Port
LED	Compare Match Output	D9	PB1 (OC1A)
VCC	Power	+5V	—
GND	Ground	GND	—
🧩 Code Explanation
Registers Used
Register	Purpose
TCCR1A / TCCR1B	Configure Timer1 mode and prescaler
TIMSK1	Enable Output Compare Match A interrupt
OCR1A	Holds compare match value
SREG	Global Interrupt Enable
DDRB	Configure PB1 as output
⚙️ Timer Configuration

Mode: CTC (Clear Timer on Compare Match)

Output Behavior: Toggle OC1A pin on compare match

Prescaler: 1024 (CS12 + CS10)

Compare Value: 15625

Output Pin: PB1 → Arduino D9

🧠 Working Principle

Timer1 counts from TCNT1 = 0 up to OCR1A = 15625.

When the match occurs:

The OC1A (D9) pin toggles automatically (hardware action).

The TIMER1_COMPA_vect ISR triggers (software interrupt).

Inside the ISR, TCNT1 and OCR1A are reloaded for continuous operation.

This generates a 1 Hz square wave on D9 — LED toggles every second.

📏 Calculation

Timer1 runs at 16 MHz with a prescaler = 1024
→ Timer tick = 16,000,000 / 1024 = 15625 Hz

To get a 1-second period:

OCR1A = 15625


Since the pin toggles at every compare match (half-period):

Output frequency = 0.5 Hz toggle → 1 second full ON/OFF cycle

💡 Output

LED on D9 (PB1) toggles every second.

Output is hardware-timed, precise, and CPU-independent.

Works great for square-wave generation or event timing.
