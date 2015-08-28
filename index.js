


var http=require('http');
//var gpio=require('./build/Release/gpio');
var addon=require('./build/Release/addon');




var obj = new addon.MyObject(10);
//console.log( obj.plusOne() ); // 11
//console.log( obj.plusOne() ); // 12
//console.log( obj.plusOne() ); // 13


//obj.close()
//console.log('%s %s',gpio.move(),gpio.stop());

var http = require('http'),
    fs = require('fs');
var html;

var callIndex=function( err,value)
{
	if(err) throw err;
	
	html=value;
}


fs.readFile('./index.html', function (err, html) { 
if(err) throw err;

var proces=function(request,response)
{
console.log(request.url);
if(request.url=="/RIGHT")
{
	//obj.close();
	obj.right();
	response.writeHead(200, {"Content-Type": "text/plain"});
       	response.end("Turining right");
            
	return 0;
}
else
    if(request.url=="/LEFT")
            {
	    obj.left();
            response.writeHead(200,{"Content-Type": "text/plain"});
            response.end("Turning left");
            return 0;
            }
            else if(request.url=="/FORWARD")
            {
		//obj.close();
		obj.forward();
            response.writeHead(200,{"Content-Type": "text/plain"});
            response.end("Moving forward");
            return 0;

            }
            else if(request.url=="/STOP")
            {
		obj.stop();
            response.writeHead(200,{"Content-Type": "text/plain"});
            response.end("STOPING");
            return 0;

            }
		else if(request.url=="/CLOSE")
		{	
		obj.close();
		response.writeHead(200,{"Content-Type": "text/plain"});
		response.end("CLOSED");
		return 0;	
		}
	   else if(request.url=="/OPEN")
	{
		response.writeHead(200,{"Content-Type":"text/plain"});
		response.end(obj.open());
		
		//obj.open();
		return 0;	
	}		
            
response.writeHead(200, {'Content-Type': 'text/html'});
    	response.write(html);
	response.end();
            }
    	//response.end('<html><body><center><h1>Ucz sie a nie wizaze ogladaj!!!</h1></center></body></html>')


http.createServer(proces).listen(80,'0.0.0.0');

});


