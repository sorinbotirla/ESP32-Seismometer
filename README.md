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
      <img src="https://raw.githubusercontent.com/sorinbotirla/ESP32-Seismometer/refs/heads/main/images/ezgif-150a4649ac9565.gif" />
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
<h2>Components</h2>
You will need the following components: <br /> <br />
1x ESP32 Board <br />
1x 2.8 Inch ILI9341 TFT Display <br />
1x WS2812 slim led strip (you will only need to cut it to only 7 LEDs) <br />
1x ADS1115 16Bit ADC <br /><br />
1x Passive Buzzer<br />
1x spool of thin copper wire for soldering.<br />
1x Soldering Iron<br />
1x Solder<br />
<br />
<table valign="top">
  <tr>
    <td valign="top">
      <h3>Esp32</h3>
      <img src="https://raw.githubusercontent.com/sorinbotirla/ESP32-Seismometer/refs/heads/main/images/9283.jpg" width="200" />
    </td>
    <td valign="top">
      <h3>2.8 inch ILI9341 TFT Display</h3>
      <img src="https://raw.githubusercontent.com/sorinbotirla/ESP32-Seismometer/refs/heads/main/images/2.8inch-resistive-touch-lcd-6.jpg" width="200" />
    </td>
    <td valign="top">
      <h3>ADS1115 16 Bit ADC</h3>
      <img src="https://raw.githubusercontent.com/sorinbotirla/ESP32-Seismometer/refs/heads/main/images/ads1115-cjmcu-digital-analogic-converter-module-adc.jpg" width="150" />
    </td>
    <td valign="top">
      <h3>WS2812 Slim LED Strip</h3>
      <img src="https://raw.githubusercontent.com/sorinbotirla/ESP32-Seismometer/refs/heads/main/images/2.6mm_ultra_slim_ws2812c_2020_digital_rgb_led_strip_2_.jpg" width="200" />
    </td>
    <td valign="top">
      <h3>4.5Hz Geophone</h3>
      <img src="https://raw.githubusercontent.com/sorinbotirla/ESP32-Seismometer/refs/heads/main/images/high-sensitivity-geophone-4.5hz.jpg" width="200" />
    </td>
  </tr>
</table>
 <br />
You can use a 4.5Hz geophone or <br /> <br />
You can build a vertical pendulum using: <br /> <br />
1x Neodymium Cylinder Magnet <br />
1x Copper wire Coil <br />
1x Pendullum arm made of 4mm aluminum sheet  <br />
1x Steel leaf spring to suspend the pendullum <br />
 <br /> <br />
I'd suggest going the simple way, using the geophone.
<br />
<br />
<table>
  <tr>
    <td valign="top">
      <h3>Coils (Thinner the better)</h3>
      <img src="https://raw.githubusercontent.com/sorinbotirla/ESP32-Seismometer/refs/heads/main/images/s-l400.png" width="200" /><br />
      <img src="https://raw.githubusercontent.com/sorinbotirla/ESP32-Seismometer/refs/heads/main/images/41XTCZcrocL._UF1000,1000_QL80_.jpg" width="200" /><br />
      <img src="https://raw.githubusercontent.com/sorinbotirla/ESP32-Seismometer/refs/heads/main/images/enameled-copper-wire-500x500.webp" width="200" />
    </td>
    <td valign="top">
      <h3>Magnet</h3>
      <img src="https://raw.githubusercontent.com/sorinbotirla/ESP32-Seismometer/refs/heads/main/images/neodymium-cylinder-magnet-25mm-x-25mm-n52-344642_450x.webp" width="300" />
    </td>
    <td valign="top">
      <h3>Aluminum sheets (Do not use steel)</h3>
      <img src="https://raw.githubusercontent.com/sorinbotirla/ESP32-Seismometer/refs/heads/main/images/aluminum-plain-sheet-500x500.webp" width="200" /><br />
      <img src="https://raw.githubusercontent.com/sorinbotirla/ESP32-Seismometer/refs/heads/main/images/Aluminum-Sheet-28.webp" width="200" />
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
