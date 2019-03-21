var moment = require('moment');
var http = require('http');
var rn = require('random-number');
var SerialPort = require('serialport');
var Readline = SerialPort.parsers.Readline;
var port = new SerialPort('COM3');
var parser = port.pipe(new Readline());
var packet;

var options = {
    // example input , yes negative values do work
    min:1
  , max:30
  ,integer:true  }

var app = http.createServer(function(req,res){
 res.setHeader('Content-Type', 'application/json');
    res.setHeader('Access-Control-Allow-Origin', '*');
    var i = 0;
    parser.on('data', function (data) {
    
    while(i<1){

    var arr = data.split(',');

    var num1 = arr[0];
    var hum1 = arr[1];

    var num2 = arr[2];
    var hum2 = arr[3];

    var num3 = arr[4];
    var hum3 = arr[5];

    var timenow=moment().format('LTS');
    res.end(JSON.stringify({ time: timenow , temp1: num1 , humi1: hum1 , temp2: num2 , humi2: hum2 , temp3: num3 , humi3: hum3}));
    //res.end(JSON.stringify({ time: timenow , temp1: num1 , humi1: hum1}));
    console.log(timenow+" "+num1+" "+hum1+" "+num2+" "+hum2+" "+num3+" "+hum3);
    i++;
    }
})

    
});
app.listen(3000);