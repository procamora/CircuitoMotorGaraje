# CircuitoMotorGaraje
Codigo y circuito para activar el motor de una puerta de garaje




## Tareas

 - [ ] Comprobar `if (clicked) delay(1000);` con la puerta del garaje
 - [ ] Checkear que funciona bien el reset por software
 - [ ] Implementar  Watch Dog Timer


La automata con los distintos estados

![Automata][automata]



El esquema de conexiones

![Eschematic][eschematic]



El pcb

![PCB][pcb]







# Lista de componentes

Ponerlo bonito


```csv
Designator	Footprint	Mid X	Mid Y	Ref X	Ref Y	Pad X	Pad Y	Layer	Rotation	Comment
"LED1"	"LED-3MM/2.54"	"19.3mm"	"61.83mm"	"19.3mm"	"63.2mm"	"19.3mm"	"63.1mm"	"T"	"0"	"LED-3MM"
"P1"	"WJ2EDGVC-5.08-2P"	"9.6mm"	"80.76mm"	"9.6mm"	"80.8mm"	"9.6mm"	"78.26mm"	"T"	"90"	"220V"
"D4"	"DO-35"	"72.9mm"	"78.41mm"	"76.71mm"	"78.41mm"	"76.71mm"	"78.41mm"	"T"	"180"	"1N4007"
"D3"	"DO-35"	"72.73mm"	"88.06mm"	"76.54mm"	"88.06mm"	"76.54mm"	"88.06mm"	"T"	"180"	"1N4007"
"T1"	"BV EI 305 2052"	"48.61mm"	"81.11mm"	"38.61mm"	"91.11mm"	"58.61mm"	"86.11mm"	"T"	"0"	"220 12 125mA"
"R11"	"AXIAL-0.3"	"70.11mm"	"60.7mm"	"66.3mm"	"60.7mm"	"66.3mm"	"60.7mm"	"T"	"0"	"47k"
"R12"	"AXIAL-0.3"	"70.11mm"	"54.7mm"	"66.3mm"	"54.7mm"	"66.3mm"	"54.7mm"	"T"	"0"	"47k"
"LED2"	"LED-3MM/2.54"	"38.47mm"	"29mm"	"37.1mm"	"29mm"	"37.2mm"	"29mm"	"T"	"90"	"LED-3MM"
"LED3"	"LED-3MM/2.54"	"27.67mm"	"6.7mm"	"26.3mm"	"6.7mm"	"26.4mm"	"6.7mm"	"T"	"90"	"LED-3MM"
"Q1"	"TO-220_VERTICAL"	"48.26mm"	"36.6mm"	"50.8mm"	"36.6mm"	"50.8mm"	"36.6mm"	"T"	"180"	"TIP120"
"Q2"	"TO-220_VERTICAL"	"48.26mm"	"8.7mm"	"50.8mm"	"8.7mm"	"50.8mm"	"8.7mm"	"T"	"180"	"TIP120"
"KEY2"	"KEY-6.0*6.0-2"	"35.8mm"	"36.65mm"	"35.8mm"	"36.6mm"	"39.3mm"	"34.7mm"	"T"	"0"	"TEST_K1"
"KEY3"	"KEY-6.0*6.0-2"	"35.8mm"	"7.75mm"	"35.8mm"	"7.7mm"	"39.3mm"	"5.79mm"	"T"	"0"	"TEST_K2"
"F1"	"FUSE-M205-CLIPS"	"19.95mm"	"92.8mm"	"9.5mm"	"92.8mm"	"9.5mm"	"92.8mm"	"T"	"0"	"200mA 250VA"
"C4"	"CAP-D4.0XF1.5"	"112.05mm"	"82.7mm"	"111.3mm"	"82.7mm"	"112.8mm"	"82.7mm"	"T"	"270"	"1u"
"R1"	"AXIAL-0.6"	"28.8mm"	"78.2mm"	"28.8mm"	"78.2mm"	"28.8mm"	"70.58mm"	"T"	"90"	"100k"
"P2"	"WJ2EDGVC-5.08-3P"	"106.93mm"	"91.36mm"	"106.93mm"	"91.36mm"	"101.85mm"	"91.36mm"	"T"	"0"	"RECEPTOR"
"R9"	"AXIAL-0.3"	"30.49mm"	"29.1mm"	"34.3mm"	"29.1mm"	"34.3mm"	"29.1mm"	"T"	"180"	"1k8"
"R10"	"AXIAL-0.3"	"19.49mm"	"6.7mm"	"23.3mm"	"6.7mm"	"23.3mm"	"6.7mm"	"T"	"180"	"1k8"
"D5"	"DO-35"	"47.8mm"	"49.41mm"	"47.8mm"	"45.6mm"	"47.8mm"	"45.6mm"	"T"	"90"	"1N4007"
"D6"	"DO-35"	"49.3mm"	"17.51mm"	"49.3mm"	"13.7mm"	"49.3mm"	"13.7mm"	"T"	"90"	"1N4007"
"C1"	"CAP-D12.5XF5.0"	"84.67mm"	"86.16mm"	"84.8mm"	"88.7mm"	"84.67mm"	"88.7mm"	"T"	"0"	"50V 2200uF"
"D1"	"DO-35"	"72.9mm"	"92.89mm"	"69.09mm"	"92.89mm"	"69.09mm"	"92.89mm"	"T"	"0"	"1N4007"
"D2"	"DO-35"	"72.9mm"	"83.24mm"	"69.09mm"	"83.24mm"	"69.09mm"	"83.24mm"	"T"	"0"	"1N4007"
"R13"	"AXIAL-0.5"	"91.8mm"	"96.7mm"	"91.8mm"	"96.7mm"	"98.15mm"	"96.7mm"	"T"	"180"	"1M"
"LED4"	"LED-3MM/2.54"	"75.6mm"	"12.23mm"	"75.6mm"	"13.6mm"	"75.6mm"	"13.5mm"	"T"	"0"	"LED-3MM"
"R3"	"AXIAL-0.3"	"66.01mm"	"13.5mm"	"62.2mm"	"13.5mm"	"62.2mm"	"13.5mm"	"T"	"0"	"680"
"P4"	"WJ2EDGVC-5.08-3P"	"111.3mm"	"59.7mm"	"111.3mm"	"59.7mm"	"111.3mm"	"64.78mm"	"T"	"270"	"FIN CARRERA"
"R5"	"AXIAL-0.3"	"108.97mm"	"47.93mm"	"105.16mm"	"47.93mm"	"105.16mm"	"47.93mm"	"T"	"0"	"10k"
"R6"	"AXIAL-0.3"	"108.97mm"	"42.6mm"	"105.16mm"	"42.6mm"	"105.16mm"	"42.6mm"	"T"	"0"	"10k"
"R7"	"AXIAL-0.3"	"70.11mm"	"47.7mm"	"66.3mm"	"47.7mm"	"66.3mm"	"47.7mm"	"T"	"0"	"2k2"
"R8"	"AXIAL-0.3"	"70.11mm"	"41.7mm"	"66.3mm"	"41.7mm"	"66.3mm"	"41.7mm"	"T"	"0"	"2k2"
"C5"	"CAP-D4.0XF1.5"	"103.55mm"	"82.7mm"	"104.3mm"	"82.7mm"	"102.8mm"	"82.7mm"	"T"	"90"	"1u"
"R4"	"AXIAL-0.3"	"101.4mm"	"46.79mm"	"101.4mm"	"50.6mm"	"101.4mm"	"50.6mm"	"T"	"270"	"10k"
"U5"	"ARDUINO_PRO_MICRO"	"82.73mm"	"27.49mm"	"84mm"	"28mm"	"96.7mm"	"35.11mm"	"T"	"270"	"ARDUINO_PRO_MICRO"
"U3"	"TO-220(TO-220-3)"	"108.89mm"	"74.2mm"	"111.3mm"	"74.2mm"	"111.43mm"	"74.2mm"	"T"	"270"	"L7805"
"U1"	"TO-220(TO-220-3)"	"86.5mm"	"67.69mm"	"86.5mm"	"70.1mm"	"86.5mm"	"70.22mm"	"T"	"0"	"L7812"
"U2"	"TO-220(TO-220-3)"	"86.6mm"	"49.49mm"	"86.6mm"	"51.9mm"	"86.6mm"	"52.03mm"	"T"	"0"	"L7805"
"PR1"	"RES-ADJ_EVN6X6"	"86.5mm"	"11.8mm"	"89mm"	"9.3mm"	"89mm"	"9.3mm"	"T"	"180"	"Potenciometro"
"R14"	"AXIAL-0.5"	"7.3mm"	"24.2mm"	"7.3mm"	"24.2mm"	"7.3mm"	"17.85mm"	"T"	"90"	"1M"
"K1"	"SPDT 5MM"	"29.8mm"	"48.35mm"	"45.3mm"	"54.6mm"	"42.3mm"	"52.1mm"	"T"	"270"	"12V 16A"
"K2"	"SPDT 5MM"	"29.8mm"	"17.95mm"	"45.3mm"	"24.2mm"	"42.3mm"	"21.7mm"	"T"	"270"	"12V 16A"
"F2"	"FUSE-M205-CLIPS"	"8.19mm"	"62.55mm"	"8.19mm"	"73mm"	"8.19mm"	"73mm"	"T"	"270"	"2A 250VA"
"P3"	"WJ2EDGVC-5.08-3P"	"8.8mm"	"41.7mm"	"8.8mm"	"41.7mm"	"8.8mm"	"36.62mm"	"T"	"90"	"MOTOR"
```













[pcb]: PCB_PCB_20190225212809.png
[eschematic]: Schematic_CircuitoMotorGaraje_Esquema_20190225212752.png
[automata]: Automata.jpg



https://easyeda.com/editor#id=f6a1cdd272174ffab44827535418baf6