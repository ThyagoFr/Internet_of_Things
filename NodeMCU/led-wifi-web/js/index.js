function sendRequest(status) {
    var xmlhttp = new XMLHttpRequest();
    var set_status = "http://192.168.0.103/?function=" + status;
    xmlhttp.open("GET", set_status);
    xmlhttp.setRequestHeader('Access-Control-Allow-Origin', '*');
    xmlhttp.setRequestHeader('Access-Control-Allow-Methods', 'GET, POST, OPTIONS, PUT, PATCH, DELETE');
    xmlhttp.setRequestHeader('Access-Control-Allow-Headers', 'Access-Control-Allow-Headers, Origin,Accept, X-Requested-With, Content-Type, Access-Control-Request-Method, Access-Control-Request-Headers');
    xmlhttp.send();
}

function toggleLamp(lamp) {
    var status_esq = document.getElementById("led_esquerda")
    var status_dir = document.getElementById("led_direita")
    var btn_esq = document.getElementById("btn-esquerda")
    var btn_dir = document.getElementById("btn-direita")

    console.log(lamp)
    if (lamp === "direita") {
        if (status_dir.innerHTML.includes("OFF")) {
            btn_dir.innerHTML = "Desligar Lampada"
            status_dir.innerHTML = "Lampâda Esquerda - ON"
            sendRequest("led3_ON")
        } else {
            btn_dir.innerHTML = "Ligar Lampada"
            status_dir.innerHTML = "Lampâda Esquerda - OFF"
            sendRequest("led3_OFF")
        }
    } else {
        if (status_esq.innerHTML.includes("OFF")) {
            btn_esq.innerHTML = "Desligar Lampada"
            status_esq.innerHTML = "Lampâda Esquerda - ON"
            sendRequest("led7_ON")
        } else {
            btn_esq.innerHTML = "Ligar Lampada"
            status_esq.innerHTML = "Lampâda Esquerda - OFF"
            sendRequest("led7_OFF")
        }
    }
}