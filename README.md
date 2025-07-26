<h1>ESP32 Seismometer</h1>
<br />
This seismometer is built using any ESP32 (I have used ESP32 Wroom).<br />
It features a 2.8 inch ILI9341 TFT Display, ADS1115 16bit ADC, a coil/magnet vertical pendullum, visual and acoustic feedback via 7x WS2812 LEDS and 1 passive buzzer.<br />
You can use a 4.5Hz geophone instead of the coil.
<br />
<br />
<h2>Pictures</h2>
<table width="100%">
  <tr>
    <td>
      <img src="https://raw.githubusercontent.com/sorinbotirla/ESP32-Seismometer/refs/heads/main/images/ezgif-10ff02c8f18650.gif" />
    </td>
    <td>
      <img src="https://raw.githubusercontent.com/sorinbotirla/ESP32-Seismometer/refs/heads/main/images/20250726_102447.jpg" />
    </td>
    <td>
      <img src="https://raw.githubusercontent.com/sorinbotirla/ESP32-Seismometer/refs/heads/main/images/20250726_102449.jpg" />
    </td>
  </tr>
  <tr>
    <td>
      <img src="https://raw.githubusercontent.com/sorinbotirla/ESP32-Seismometer/refs/heads/main/images/20250726_102458.jpg" />
    </td>
    <td>
      <img src="https://raw.githubusercontent.com/sorinbotirla/ESP32-Seismometer/refs/heads/main/images/20250726_102503.jpg" />
    </td>
    <td>
      <img src="https://raw.githubusercontent.com/sorinbotirla/ESP32-Seismometer/refs/heads/main/images/20250726_102518.jpg" />
    </td>
  </tr>

  <tr>
    <td>
      <img src="https://raw.githubusercontent.com/sorinbotirla/ESP32-Seismometer/refs/heads/main/images/20250726_112213.jpg" />
    </td>
    <td>
      <img src="https://raw.githubusercontent.com/sorinbotirla/ESP32-Seismometer/refs/heads/main/images/20250726_112231.jpg" />
    </td>
    <td>
      <img src="https://raw.githubusercontent.com/sorinbotirla/ESP32-Seismometer/refs/heads/main/images/20250726_112241.jpg" />
    </td>
  </tr>
  <tr>
    <td>
      <img src="https://raw.githubusercontent.com/sorinbotirla/ESP32-Seismometer/refs/heads/main/images/20250726_112248.jpg" />
    </td>
    <td>
      <img src="https://raw.githubusercontent.com/sorinbotirla/ESP32-Seismometer/refs/heads/main/images/20250726_112301.jpg" />
    </td>
    <td>
      <img src="https://raw.githubusercontent.com/sorinbotirla/ESP32-Seismometer/refs/heads/main/images/20250726_112313.jpg" />
    </td>
  </tr>
</table>
<br />
<br />
<h2>Pinout</h2>
<table border="1" cellpadding="5" cellspacing="0"  width="100%">
  <tr>
    <th>ESP32</th>
    <th>ADS1115</th>
    <th>COIL</th>
    <th>Buzzer</th>
    <th>WS2812 LED</th>
    <th>ILI9341 Display</th>
    <th>Touch</th>
  </tr>
  <tr>
    <td>3.3V</td>
    <td>VDD</td>
    <td></td>
    <td></td>
    <td></td>
    <td>VCC</td>
    <td></td>
  </tr>
  <tr>
    <td>5V</td>
    <td></td>
    <td></td>
    <td></td>
    <td>LED (+)</td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>GND</td>
    <td>GND</td>
    <td></td>
    <td>SPEAKER (-)</td>
    <td>LED (-)</td>
    <td>GND</td>
    <td>GND</td>
  </tr>
  <tr>
    <td>4</td>
    <td></td>
    <td></td>
    <td>SPEAKER (+)</td>
    <td></td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>5</td>
    <td></td>
    <td></td>
    <td></td>
    <td></td>
    <td>RST</td>
    <td></td>
  </tr>
  <tr>
    <td>15</td>
    <td></td>
    <td></td>
    <td></td>
    <td></td>
    <td>BL (Backlight)</td>
    <td></td>
  </tr>
  <tr>
    <td>16</td>
    <td></td>
    <td></td>
    <td></td>
    <td></td>
    <td>DC</td>
    <td></td>
  </tr>
  <tr>
    <td>17</td>
    <td></td>
    <td></td>
    <td></td>
    <td></td>
    <td>CS</td>
    <td></td>
  </tr>
  <tr>
    <td>18</td>
    <td></td>
    <td></td>
    <td></td>
    <td></td>
    <td>SCK</td>
    <td></td>
  </tr>
  <tr>
    <td>19</td>
    <td></td>
    <td></td>
    <td></td>
    <td></td>
    <td>MISO</td>
    <td></td>
  </tr>
  <tr>
    <td>21</td>
    <td>SDA</td>
    <td></td>
    <td></td>
    <td></td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>22</td>
    <td>SCL</td>
    <td></td>
    <td></td>
    <td></td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>23</td>
    <td></td>
    <td></td>
    <td></td>
    <td></td>
    <td>MOSI</td>
    <td></td>
  </tr>
  <tr>
    <td>25</td>
    <td></td>
    <td></td>
    <td></td>
    <td>LED DATA</td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>33</td>
    <td></td>
    <td></td>
    <td></td>
    <td></td>
    <td></td>
    <td>Touch CS</td>
  </tr>
  <tr>
    <td></td>
    <td>A0</td>
    <td>COIL (+)</td>
    <td></td>
    <td></td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td></td>
    <td>A1</td>
    <td>COIL (–)</td>
    <td></td>
    <td></td>
    <td></td>
    <td></td>
  </tr>
</table>
