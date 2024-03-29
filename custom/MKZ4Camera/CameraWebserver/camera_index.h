const char *index_ov2640_html = R"=====(
<!DOCTYPE html>
<html><head><meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<meta name="viewport" content="width=device-width,initial-scale=1">
<title>MKZ4 Camera</title>
<style>
body {
font-family: Arial,Helvetica,sans-serif;
background: #2d91ee;
color: #EFEFEF;
font-size: 16px
}

h2 {font-size: 18px}
section.main {display: flex}
#menu,section.main {flex-direction: column}

#menu {
display: none;
flex-wrap: nowrap;
min-width: 340px;
background: #3d7ab4;
padding: 8px;
border-radius: 4px;
margin-top: -10px;
margin-right: 10px;
}

#content {
display: flex;
flex-wrap: wrap;
align-items: stretch
}

figure {
padding: 0px;
margin: 0;
-webkit-margin-before: 0;
margin-block-start: 0;
-webkit-margin-after: 0;
margin-block-end: 0;
-webkit-margin-start: 0;
margin-inline-start: 0;
-webkit-margin-end: 0;
margin-inline-end: 0
}

figure img {
display: block;
width: 100%;
height: auto;
border-radius: 4px;
margin-top: 8px;
}

@media (min-width: 800px) and (orientation:landscape) {
#content {
display:flex;
flex-wrap: nowrap;
align-items: stretch
}

figure img {
display: block;
max-width: 100%;
max-height: calc(100vh - 40px);
width: auto;
height: auto
}

figure {
padding: 0 0 0 0px;
margin: 0;
-webkit-margin-before: 0;
margin-block-start: 0;
-webkit-margin-after: 0;
margin-block-end: 0;
-webkit-margin-start: 0;
margin-inline-start: 0;
-webkit-margin-end: 0;
margin-inline-end: 0
}
}

section#buttons {
display: flex;
flex-wrap: nowrap;
justify-content: space-between
}

#nav-toggle {
cursor: pointer;
display: block
}

#nav-toggle-cb {
outline: 0;
opacity: 0;
width: 0;
height: 0
}

#nav-toggle-cb:checked+#menu {
display: flex
}

.input-group {
display: flex;
flex-wrap: nowrap;
line-height: 22px;
margin: 5px 0
}

.input-group>label {
display: inline-block;
padding-right: 10px;
min-width: 47%
}

.input-group input,.input-group select {
flex-grow: 1
}

.range-max,.range-min {
display: inline-block;
padding: 0 5px
}

button, .button {
display: block;
margin: 5px;
padding: 0 12px;
border: 0;
line-height: 28px;
cursor: pointer;
color: #fff;
background: #2e5880;
border-radius: 5px;
font-size: 16px;
outline: 0
}

.save {
position: absolute;
right: 25px;
top: 0px;
height: 16px;
line-height: 16px;
padding: 0 4px;
text-decoration: none;
cursor: pointer
}

button:hover {
background: #0050fd
}

button:active {
background: #0050fd
}

button.disabled {
cursor: default;
background: #a0a0a0
}

input[type=range] {
-webkit-appearance: none;
width: 100%;
height: 22px;
background: #2e5880;
cursor: pointer;
margin: 0
}

input[type=range]:focus {
outline: 0
}

input[type=range]::-webkit-slider-runnable-track {
width: 100%;
height: 2px;
cursor: pointer;
background: #EFEFEF;
border-radius: 0;
border: 0 solid #EFEFEF
}

input[type=range]::-webkit-slider-thumb {
border: 1px solid rgba(0,0,30,0);
height: 22px;
width: 22px;
border-radius: 50px;
background: #0050fd;
cursor: pointer;
-webkit-appearance: none;
margin-top: -11.5px
}

input[type=range]:focus::-webkit-slider-runnable-track {
background: #EFEFEF
}

input[type=range]::-moz-range-track {
width: 100%;
height: 2px;
cursor: pointer;
background: #EFEFEF;
border-radius: 0;
border: 0 solid #EFEFEF
}

input[type=range]::-moz-range-thumb {
border: 1px solid rgba(0,0,30,0);
height: 22px;
width: 22px;
border-radius: 50px;
background: #0050fd;
cursor: pointer
}

input[type=range]::-ms-track {
width: 100%;
height: 2px;
cursor: pointer;
background: 0 0;
border-color: transparent;
color: transparent
}

input[type=range]::-ms-fill-lower {
background: #EFEFEF;
border: 0 solid #EFEFEF;
border-radius: 0
}

input[type=range]::-ms-fill-upper {
background: #EFEFEF;
border: 0 solid #EFEFEF;
border-radius: 0
}

input[type=range]::-ms-thumb {
border: 1px solid rgba(0,0,30,0);
height: 22px;
width: 22px;
border-radius: 50px;
background: #0050fd;
cursor: pointer;
height: 2px
}

input[type=range]:focus::-ms-fill-lower {background: #EFEFEF}
input[type=range]:focus::-ms-fill-upper {background: #363636}

.switch {
display: block;
position: relative;
line-height: 22px;
font-size: 16px;
height: 22px
}

.switch input {
outline: 0;
opacity: 0;
width: 0;
height: 0
}

.slider {
width: 50px;
height: 22px;
border-radius: 22px;
cursor: pointer;
background-color: grey
}

.slider,.slider:before {
display: inline-block;
transition: .4s
}

.slider:before {
position: relative;
content: "";
border-radius: 50%;
height: 16px;
width: 16px;
left: 4px;
top: 3px;
background-color: #fff
}

input:checked+.slider {background-color: #0050fd}

input:checked+.slider:before {
-webkit-transform: translateX(26px);
transform: translateX(26px)
}

select {
border: 1px solid #363636;
font-size: 14px;
height: 22px;
outline: 0;
border-radius: 5px
}

.image-container {
position: relative;
min-width: 160px
}

.close {
position: absolute;
right: 5px;
top: 5px;
background: #3d7ab4;
width: 16px;
height: 16px;
border-radius: 100px;
color: #fff;
text-align: center;
line-height: 18px;
cursor: pointer
}

.hidden {display: none}

input[type=text] {
border: 1px solid #363636;
font-size: 14px;
height: 20px;
margin: 1px;
outline: 0;
border-radius: 5px
}

.inline-button {
line-height: 20px;
margin: 2px;
padding: 1px 4px 2px 4px;
}

label.toggle-section-label {
cursor: pointer;
display: block
}

input.toggle-section-button {
outline: 0;
opacity: 0;
width: 0;
height: 0
}

input.toggle-section-button:checked+section.toggle-section {display: none}
</style></head>

<body>
<section class="main">
<div id="logo">
<label for="nav-toggle-cb" id="nav-toggle">☰&nbsp;&nbsp;Settings</label>
</div>
<div id="content">

<div id="sidebar">
<input type="checkbox" id="nav-toggle-cb" checked="checked">
<nav id="menu">

<div class="input-group" id="framesize-group">
<label for="framesize">Resolution</label>
<select id="framesize" class="default-action">
<!-- 2MP -->
<option value="13">UXGA(1600x1200)</option>
<option value="12">SXGA(1280x1024)</option>
<option value="11">HD(1280x720)</option>
<option value="10">XGA(1024x768)</option>
<option value="9">SVGA(800x600)</option>
<option value="8">VGA(640x480)</option>
<option value="7">HVGA(480x320)</option>
<option value="6">CIF(400x296)</option>
<option value="5">QVGA(320x240)</option>
<option value="4">240x240</option>
<option value="3">HQVGA(240x176)</option>
<option value="2">QCIF(176x144)</option>
<option value="1">QQVGA(160x120)</option>
<option value="0">96x96</option>
</select>
</div>
<div class="input-group" id="quality-group">
<label for="quality">Quality</label>
<div class="range-min">4</div>
<input type="range" id="quality" min="4" max="63" value="10" class="default-action">
<div class="range-max">63</div>
</div>
<div class="input-group" id="brightness-group">
<label for="brightness">Brightness</label>
<div class="range-min">-2</div>
<input type="range" id="brightness" min="-2" max="2" value="0" class="default-action">
<div class="range-max">2</div>
</div>
<div class="input-group" id="contrast-group">
<label for="contrast">Contrast</label>
<div class="range-min">-2</div>
<input type="range" id="contrast" min="-2" max="2" value="0" class="default-action">
<div class="range-max">2</div>
</div>
<div class="input-group" id="saturation-group">
<label for="saturation">Saturation</label>
<div class="range-min">-2</div>
<input type="range" id="saturation" min="-2" max="2" value="0" class="default-action">
<div class="range-max">2</div>
</div>

<div class="input-group" id="awb-group">
<label for="awb">AWB</label>
<div class="switch">
<input id="awb" type="checkbox" class="default-action" checked="checked">
<label class="slider" for="awb"></label>
</div>
</div>
<div class="input-group" id="awb_gain-group">
<label for="awb_gain">AWB Gain</label>
<div class="switch">
<input id="awb_gain" type="checkbox" class="default-action" checked="checked">
<label class="slider" for="awb_gain"></label>
</div>
</div>
<div class="input-group" id="wb_mode-group">
<label for="wb_mode">WB Mode</label>
<select id="wb_mode" class="default-action">
<option value="0" selected="selected">Auto</option>
<option value="1">Sunny</option>
<option value="2">Cloudy</option>
<option value="3">Office</option>
<option value="4">Home</option>
</select>
</div>
<div class="input-group" id="aec-group">
<label for="aec">AEC SENSOR</label>
<div class="switch">
<input id="aec" type="checkbox" class="default-action" checked="checked">
<label class="slider" for="aec"></label>
</div>
</div>
<div class="input-group" id="aec2-group">
<label for="aec2">AEC DSP</label>
<div class="switch">
<input id="aec2" type="checkbox" class="default-action" checked="checked">
<label class="slider" for="aec2"></label>
</div>
</div>
<div class="input-group" id="ae_level-group">
<label for="ae_level">AE Level</label>
<div class="range-min">-2</div>
<input type="range" id="ae_level" min="-2" max="2" value="0" class="default-action">
<div class="range-max">2</div>
</div>
<div class="input-group hidden" id="aec_value-group">
<label for="aec_value">Exposure</label>
<div class="range-min">0</div>
<input type="range" id="aec_value" min="0" max="1200" value="204" class="default-action">
<div class="range-max">1200</div>
</div>
<div class="input-group" id="agc-group">
<label for="agc">AGC</label>
<div class="switch">
<input id="agc" type="checkbox" class="default-action" checked="checked">
<label class="slider" for="agc"></label>
</div>
</div>
<div class="input-group hidden" id="agc_gain-group">
<label for="agc_gain">Gain</label>
<div class="range-min">1x</div>
<input type="range" id="agc_gain" min="0" max="30" value="5" class="default-action">
<div class="range-max">31x</div>
</div>
<div class="input-group" id="gainceiling-group">
<label for="gainceiling">Gain Ceiling</label>
<div class="range-min">2x</div>
<input type="range" id="gainceiling" min="0" max="6" value="0" class="default-action">
<div class="range-max">128x</div>
</div>
<div class="input-group" id="bpc-group">
<label for="bpc">BPC</label>
<div class="switch">
<input id="bpc" type="checkbox" class="default-action">
<label class="slider" for="bpc"></label>
</div>
</div>
<div class="input-group" id="wpc-group">
<label for="wpc">WPC</label>
<div class="switch">
<input id="wpc" type="checkbox" class="default-action" checked="checked">
<label class="slider" for="wpc"></label>
</div>
</div>
<div class="input-group" id="raw_gma-group">
<label for="raw_gma">Raw GMA</label>
<div class="switch">
<input id="raw_gma" type="checkbox" class="default-action" checked="checked">
<label class="slider" for="raw_gma"></label>
</div>
</div>
<div class="input-group" id="lenc-group">
<label for="lenc">Lens Correction</label>
<div class="switch">
<input id="lenc" type="checkbox" class="default-action" checked="checked">
<label class="slider" for="lenc"></label>
</div>
</div>
<div class="input-group" id="hmirror-group">
<label for="hmirror">H-Mirror</label>
<div class="switch">
<input id="hmirror" type="checkbox" class="default-action" checked="checked">
<label class="slider" for="hmirror"></label>
</div>
</div>
<div class="input-group" id="vflip-group">
<label for="vflip">V-Flip</label>
<div class="switch">
<input id="vflip" type="checkbox" class="default-action" checked="checked">
<label class="slider" for="vflip"></label>
</div>
</div>
<div class="input-group" id="dcw-group">
<label for="dcw">DCW (Downsize EN)</label>
<div class="switch">
<input id="dcw" type="checkbox" class="default-action" checked="checked">
<label class="slider" for="dcw"></label>
</div>
</div>
<div class="input-group" id="colorbar-group">
<label for="colorbar">Color Bar</label>
<div class="switch">
<input id="colorbar" type="checkbox" class="default-action">
<label class="slider" for="colorbar"></label>
</div>
</div>

<section id="buttons">
<button id="toggle-stream">Start Stream</button>
</section>

</nav></div>
<figure>
<div id="stream-container" class="image-container hidden">
<div class="close" id="close-stream">×</div>
<img id="stream" src="http://192.168.4.1/" crossorigin="">
</div></figure>
</div></section>
<div class="card" id="card">
<svg height="600px" width="100%" style="stroke:rgb(200,200,200);stroke-width:1">
<line x1="50%" y1="0" x2="50%" y2="100%" />
<line x1="0" y1="50%" x2="100%" y2="50%" />
</svg>
</div>

<script>
let gateway = `ws://${window.location.hostname}/ws`
let websocket
let firstConnection = true

document.addEventListener('DOMContentLoaded', function (event) {
let baseHost = document.location.origin
let streamUrl = baseHost + ':81'

function initWebSocket() {
console.log('Trying to open a WebSocket connection...')
websocket = new WebSocket(gateway)
websocket.onopen = onOpen
websocket.onclose = onClose
websocket.onmessage = onMessage
}

function onOpen(){
if(firstConnection){
alert("connected")
firstConnection = false
}}

function onClose() {
initWebSocket()}

function onMessage(event) {
let state
if (event.data == "1") {state = "ON"}
else {state = "OFF"}
}

function move(movement){
console.log(movement)
if (typeof websocket !== 'undefined'){
websocket.send(movement)
}}

initWebSocket();

function fetchUrl(url, cb){
fetch(url).then(function (response) {
if (response.status !== 200) {
cb(response.status, response.statusText);
} else {
response.text().then(function(data){
cb(200, data);
}).catch(function(err) {
cb(-1, err);
});
}})
.catch(function(err) {
cb(-1, err);
});
}

function setWindow(start_x, start_y, end_x, end_y, offset_x, offset_y, total_x, total_y, output_x, output_y, scaling, binning, cb){
fetchUrl(`${baseHost}/resolution?sx=${start_x}&sy=${start_y}&ex=${end_x}&ey=${end_y}&offx=${offset_x}&offy=${offset_y}&tx=${total_x}&ty=${total_y}&ox=${output_x}&oy=${output_y}&scale=${scaling}&binning=${binning}`, cb);
}

const updateRegValue = (el, value, updateRemote) => {
let initialValue
let offset = el.attributes.offset?parseInt(el.attributes.offset.nodeValue):0;
let mask = (el.attributes.mask?parseInt(el.attributes.mask.nodeValue):255) << offset;
value = (value & mask) >> offset;
if (el.type === 'checkbox') {
initialValue = el.checked
value = !!value
el.checked = value
} else {
initialValue = el.value
el.value = value
}}

const hide = el => {el.classList.add('hidden')}
const show = el => {el.classList.remove('hidden')}

const disable = el => {
el.classList.add('disabled')
el.disabled = true
}

const enable = el => {
el.classList.remove('disabled')
el.disabled = false
}

const updateValue = (el, value, updateRemote) => {
updateRemote = updateRemote == null ? true : updateRemote
let initialValue
if (el.type === 'checkbox') {
initialValue = el.checked
value = !!value
el.checked = value
} else {
initialValue = el.value
el.value = value
}

if (updateRemote && initialValue !== value) {
updateConfig(el);
} else if(!updateRemote){
if(el.id === "aec"){
value ? hide(exposure) : show(exposure)
} else if(el.id === "agc"){
if (value) {
show(gainCeiling)
hide(agcGain)
} else {
hide(gainCeiling)
show(agcGain)
}} else if(el.id === "awb_gain"){value ? show(wb) : hide(wb)}
}}

function updateConfig (el) {
let value
switch (el.type) {
case 'checkbox':
value = el.checked ? 1 : 0
break
case 'range':
case 'select-one':
value = el.value
break
case 'button':
case 'submit':
value = '1'
break
default:
return
}

const query = `${baseHost}/control?var=${el.id}&val=${value}`
fetch(query).then(response => {console.log(`request to ${query} finished, status: ${response.status}`)})
}
document.querySelectorAll('.close').forEach(el => {el.onclick = () => {hide(el.parentNode)}})

// read initial values
fetch(`${baseHost}/status`).then(function (response) {return response.json()})
.then(function (state) {document.querySelectorAll('.default-action').forEach(el => {updateValue(el, state[el.id], false)})

})

const view = document.getElementById('stream')
const viewContainer = document.getElementById('stream-container')
const streamButton = document.getElementById('toggle-stream')
const closeButton = document.getElementById('close-stream')

const stopStream = () => {
window.stop();
streamButton.innerHTML = 'Start Stream'
}

const startStream = () => {
view.src = `${streamUrl}/stream`
show(viewContainer)
streamButton.innerHTML = 'Stop Stream'
}

closeButton.onclick = () => {
stopStream()
hide(viewContainer)
}

streamButton.onclick = () => {
const streamEnabled = streamButton.innerHTML === 'Stop Stream'
if (streamEnabled) {stopStream()}
else {startStream()}
}

// Attach default on change action
document.querySelectorAll('.default-action')
.forEach(el => {el.onchange = () => updateConfig(el)})

// Custom actions
// Gain
const agc = document.getElementById('agc')
const agcGain = document.getElementById('agc_gain-group')
const gainCeiling = document.getElementById('gainceiling-group')
agc.onchange = () => {
updateConfig(agc)
if (agc.checked) {
show(gainCeiling)
hide(agcGain)
} else {
hide(gainCeiling)
show(agcGain)
}
}

// Exposure
const aec = document.getElementById('aec')
const exposure = document.getElementById('aec_value-group')
aec.onchange = () => {
updateConfig(aec)
aec.checked ? hide(exposure) : show(exposure)
}

// AWB
const awb = document.getElementById('awb_gain')
const wb = document.getElementById('wb_mode-group')
awb.onchange = () => {
updateConfig(awb)
awb.checked ? show(wb) : hide(wb)
}

const framesize = document.getElementById('framesize')

framesize.onchange = () => {
updateConfig(framesize)
}

function disableWS() {
enableWScommunication = false
move(0,0)
}

const area = document.getElementById("card")
let enableWScommunication = false;
area.addEventListener("touchstart", function (){enableWScommunication = true});
area.addEventListener("touchend", disableWS);

area.ontouchmove = function (evt) {
evt.preventDefault()
if (enableWScommunication) {
let event = evt.changedTouches[0]
let viewportOffset = area.getBoundingClientRect()
let fromCenterX = event.clientX - (area.offsetWidth / 2) - viewportOffset.left
let fromCenterY = event.clientY - (area.offsetHeight / 2) - viewportOffset.top
fromCenterX = fromCenterX * 200 / area.offsetWidth
fromCenterY = fromCenterY * 200 / area.offsetHeight
fromCenterX = Math.round(fromCenterX)
fromCenterY = Math.round(fromCenterY)
// console.log(fromCenterX + "," + fromCenterY)
move(fromCenterX.toString() + "," + fromCenterY.toString())
}}
})
</script></body></html>
)=====";
