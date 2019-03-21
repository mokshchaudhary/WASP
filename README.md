# WASP
![wasp-header](https://i.imgur.com/0ukVt3a.jpg)
</br>
WASP aims to become a framework for IoT based devices and be able to provide non-technical (or just lazy devs) a backend for their IoT devices so they can focus on solving the problem instead of the worrying about the backend. We intend to add AI modeling to the framework to provide alerts and in-depth analysis of the data.</br>Project Status: Alpha
</br>
### Wasp uses 2 modules:
- Wasp Mesh
- Wasp Modeling (coming Soon)
### Wasp Mesh:
Wasp Mesh Deals with the collection of data and showing it on a simple and intuitive form. Wasp Mesh also deals with the storage of the data.

### Wasp Modeling:
Wasp Modeling will be a AI modeling system which will can be programed (trained) as per the need of the person and will provide real time analysis and alert.
</br>
# Getting Started

Right Now WASP is designed to work with only [LoRa](http://www.heltec.cn/project/wifi-lora-32/?lang=en) Boards. You'll need at least 2 (though many boards can be used) of the development boards

1 to send data from server and 1 to act as a receiver for the data.

# Prequisites

- ## Node JS
  ### Moment:
  `npm install moment`
  ### Serial Port
  `npm install serialport`
  ### Random Number
  `npm install random-number`
- ## Arduino-IDE
     ### Libraries:
      - ESP-32
      - https://github.com/Heltec-Aaron-Lee/WiFi_Kit_series
- ## Heltech LoRa Board:
    [Get Board Here](https://www.amazon.com/s?k=heltec+lora&crid=2T4VRG0Z5SFST&sprefix=heltec+%2Caps%2C409&ref=nb_sb_ss_i_1_7)
    
- ## Apache(or any server)
  We Suggest using [XAMPP](https://www.apachefriends.org/index.html)
    
# Usage:

- ## Program the LoRa Sender:</br>
     Flash the sender LoRa Sender with the sender code </br>
     Power this board with 5v</br>
     
- ## Program the LoRa Receiver:</br>
     Flash the sender LoRa reciever with reciever code </br>
     Keep this board connected to the PC (note the port) </br>
     
     Default project uses a DHT 11 (install it's library if you want to use it or edit the code) </br>
     DHT pin 12
   
- ## Starting Node App:
    `npm start nodeserve.js` </br> </br>
  The app server the data at port 3000 </br>
  The Default COM port is port 3 (change it with LoRa Reciever Port)
  
- ## Starting the Website:
   Copy the website to the htdocs folder of the Xampp </br>
   Start the server
  
   
