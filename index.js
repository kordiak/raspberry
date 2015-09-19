


var http=require('http');

var addon=require('./build/Release/addon');




var obj = new addon.MyObject(10);

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
    


http.createServer(proces).listen(80,'0.0.0.0');

});


