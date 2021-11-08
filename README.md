# IoT-Vehicle-Monitoring-with-Blynk-n-Flask-Server

## Components
1. Proteus 8.6 SP2(for simulation)</br>
  a. Arduino</br>
  b. Temperature Sensor</br>
  c. Potentiometer in place of Accelerometer</br>
  d. Buzzer (To alert overheating)</br>
  e. LED (for testing)</br>
  f. Compim (In place of esp8266 to access a server port)</br>
2. Android Mobile</br>
  a. Blynk App</br>
3. Goormide Cloud IDE</br>
  a. Hosting a flask web server to view the temperature and acceleration data</br>
4. Virtual Serial Ports Emulator.</br>

## Implementation
1. Download Blynk App and create a new project with arduino as the main component, then copy the authentication key displayed in the app.</br>
2. Add button and live chart to the Blynk project and assign D13 pin to the button, V1 and V5 as a virtual pin to the live chart components in the app.</br>

![Screenshot from 2021-11-08 09-32-22](https://user-images.githubusercontent.com/54111714/140682618-c1324e29-583b-4e48-9408-e0e811adc9c0.png)

3. In your computer create a new project in proteus and add arduino(assuming adruino library exists in the proteus application), a LED to D13 pin and compim component connected to the arduino.</br>
4. Add a temperature sensor and potentiometer to the arduino.</br>

![Screenshot from 2021-11-08 09-31-27](https://user-images.githubusercontent.com/54111714/140682571-71f50282-599b-4ee0-bed9-20482bcc0ef5.png)

5. Open the arduino ide and compile the code then add the compiled code to the arduino component in the proteus application.</br>
6. Open Virtual Serial Ports Emulator and add pair connection between com3 and com1.</br>

![Screenshot from 2021-11-08 09-31-48](https://user-images.githubusercontent.com/54111714/140682841-dfab84ae-5537-45d7-bfb2-82b484baff3d.png)

7. Browse through the arduino library and open the blynk library folder(assuming library is installed using the arduino IDE). Open the command prompt at that particular directory and enter blynk-ser.bat -c COM1 -p 8442. This runs a server replicating esp8266 functionality.</br>
8. Run the proteus simulation and view the results in the app.</br>
9. Copy the web server code and host it on goormide to view the site.</br>

![Screenshot from 2021-11-08 09-33-20](https://user-images.githubusercontent.com/54111714/140682866-93593796-572e-4de6-a0d1-ef9283e18b0e.png)
