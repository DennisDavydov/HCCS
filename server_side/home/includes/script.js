

// time function 

function startTime() {
    var today = new Date();
    var h = today.getHours();
    var m = today.getMinutes();
    var s = today.getSeconds();
    m = checkTime(m);
    s = checkTime(s);
    document.getElementById('txt').innerHTML = h + ":" + m + ":" + s;
    var t = setTimeout(startTime, 500);
  }
  function checkTime(i) {
    if (i < 10) {i = "0" + i};  
    return i;
  }
 startTime();
//Automatically updates the current temperature
function currentTemp (){
    const xhttp = new XMLHttpRequest(); 
    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          document.querySelector("Gost").innerHTML = this.responseText; 
          
        }
    };
    xhttp.open("GET", "browser_cur_temp.in.php?temp=", true);
  xhttp.send();  
}    
currentTemp();
//const xhttp = new XMLHttpRequest(); 
//console.log(xhttp);
