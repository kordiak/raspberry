


var http=require('http');
var gpio=require('./build/Release/gpio');





console.log('%s %s',gpio.move(),gpio.stop());

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
	
	response.writeHead(200, {"Content-Type": "text/plain"});
       	response.end(gpio.right());
            
	return 0;
}
else
    if(request.url=="/LEFT")
            {
            response.writeHead(200,{"Content-Type": "text/plain"});
            response.end(gpio.left());
            return 0;
            }
            else if(request.url=="/FORWARD")
            {
            response.writeHead(200,{"Content-Type": "text/plain"});
            response.end("Moving forward");
            return 0;

            }
            else if(request.url=="/STOP")
            {
            response.writeHead(200,{"Content-Type": "text/plain"});
            response.end(gpio.stop());
            return 0;

            }
            
response.writeHead(200, {'Content-Type': 'text/html'});
    	response.write(html);
	response.end();
            }
    	//response.end('<html><body><center><h1>Ucz sie a nie wizaze ogladaj!!!</h1></center></body></html>')


http.createServer(proces).listen(80,'0.0.0.0');

});
