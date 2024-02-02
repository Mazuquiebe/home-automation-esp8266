String mountHtmlPage (
  uint16_t relay1,
  uint16_t relay2,
  uint16_t relay3,
  uint16_t relay4,
  uint16_t relay5
){
  String htmlPage; 
  
  htmlPage = "<!DOCTYPE html>";
  htmlPage += "<html lang='en'>";
  htmlPage += "  <head>";
  htmlPage += "    <meta charset='UTF-8' />";
  htmlPage += "    <meta name='viewport' content='width=device-width, initial-scale=1.0' />";
  htmlPage += "    <title>Home control</title>";
  htmlPage += "    <style>";

  htmlPage += "      body {";
  htmlPage += "        background-color: #1c2422;";
  htmlPage += "        font-family: Arial, Helvetica, sans-serif;";
  htmlPage += "        display: flex;";
  htmlPage += "        flex-direction: column;";
  htmlPage += "        align-items: center;";
  htmlPage += "        justify-content: center;";
  htmlPage += "        width: 100vw;";
  htmlPage += "        height: 100vh;";
  htmlPage += "        overflow: hidden;";
  htmlPage += "      }";

  htmlPage += "      form {";
  htmlPage += "        display: flex;";
  htmlPage += "        flex-direction: column;";
  htmlPage += "        align-items: center;";
  htmlPage += "        width: 300px;";
  htmlPage += "        background-color: #374548;";
  htmlPage += "        border-radius: 15px;";
  htmlPage += "      }";

  htmlPage += "      legend {";
  htmlPage += "        font: bold 1.5rem Arial;";
  htmlPage += "        color: #6f8a91;";
  htmlPage += "        margin-top: 10px;";
  htmlPage += "      }";

  htmlPage += "      label {";
  htmlPage += "        display: flex;";
  htmlPage += "        flex-direction: row;";
  htmlPage += "        align-items: center;";
  htmlPage += "        justify-content: center;";
  htmlPage += "        gap: 5px;";
  htmlPage += "        color: #6f8a91;";
  htmlPage += "        font: normal 1.5rem Arial;";
  htmlPage += "        margin: 10px;";
  htmlPage += "      }";

  htmlPage += "      input[type='range'] {";
  htmlPage += "        -webkit-appearance: none;";
  htmlPage += "        appearance: none;";
  htmlPage += "        background-color: #6f8a91;";
  htmlPage += "        border: none;";
  htmlPage += "        border-radius: 20px;";
  htmlPage += "        display: inline-flex;";
  htmlPage += "        width: 100px;";
  htmlPage += "        height: 40px;";
  htmlPage += "      }";
  htmlPage += "      ";
  htmlPage += "      input[type='range']::-moz-range-thumb {";
  htmlPage += "        width: 25px;";
  htmlPage += "        height: 25px;";
  htmlPage += "        border-radius: 50%;";
  htmlPage += "        background: #53676c;";
  htmlPage += "        border: none;";
  htmlPage += "      }";

  htmlPage += "      input[type='range']::-webkit-slider-thumb {";
  htmlPage += "        all: unset;";
  htmlPage += "        -webkit-appearance: none;";
  htmlPage += "        appearance: none;";
  htmlPage += "        display: flex;";
  htmlPage += "        width: 50px;";
  htmlPage += "        height: 50px;";
  htmlPage += "        border-radius: 50%;";
  htmlPage += "        background: #53676c;";
  htmlPage += "      }";

  htmlPage += "      .submit-button {";
  htmlPage += "        display: flex;";
  htmlPage += "        flex-direction: column;";
  htmlPage += "        align-items: center;";
  htmlPage += "        justify-content: center;";
  htmlPage += "        width: 80%;";
  htmlPage += "        height: 40px;";
  htmlPage += "        border-radius: 15px;";
  htmlPage += "        background: #53676c;";
  htmlPage += "        color: #fff;";
  htmlPage += "        outline: none;";
  htmlPage += "        border: none;";
  htmlPage += "        margin: 10px;";
  htmlPage += "        cursor: pointer;";
  htmlPage += "      }";

  htmlPage += "      h3 {";
  htmlPage += "        margin-top: 5px;";
  htmlPage += "        margin-bottom: 5px;";
  htmlPage += "        color: #fff;";
  htmlPage += "         }";

  htmlPage += "      .on-span {";
  htmlPage += "         color: limegreen;";
  htmlPage += "       }";
  
  htmlPage += "      .off-span {";
  htmlPage += "         color: tomato;";
  htmlPage += "       }";

  htmlPage += "    </style>";
  htmlPage += "  </head>";

  htmlPage += "  <body>";
  htmlPage += "    <form action='/' method='POST' enctype='text/plain' id='form-control'>";
  htmlPage += "      <legend>Remote Control</legend>";

  htmlPage += "      <h3>Load 1</h3>";
  htmlPage += "      <label for='relay1'>";
  htmlPage += "        <span class='off-span'>OFF</span>";
  htmlPage += "        <input type='range' name='relay1' id='relay1' min='0' max='1'";
  htmlPage += "value='" + String(digitalRead(relay1)) + "'/>";
  htmlPage += "        <span class='on-span'>ON</span>";
  htmlPage += "      </label>";

  htmlPage += "      <h3>Load 2</h3>";
  htmlPage += "      <label for='relay2'>";
  htmlPage += "        <span class='off-span'>OFF</span>";
  htmlPage += "        <input type='range' name='relay2' id='relay2' min='0' max='1'";
  htmlPage += "value='" + String(digitalRead(relay2)) + "'/>";
  htmlPage += "        <span class='on-span'>ON</span>";
  htmlPage += "      </label>";

  htmlPage += "      <h3>Load 3</h3>";
  htmlPage += "      <label for='relay3'>";
  htmlPage += "        <span class='off-span'>OFF</span>";
  htmlPage += "        <input type='range' name='relay3' id='relay3' min='0' max='1'";
  htmlPage += "value='" + String(digitalRead(relay3)) + "'/>";
  htmlPage += "        <span class='on-span'>ON</span>";
  htmlPage += "      </label>";

  htmlPage += "      <h3>Load 4</h3>";
  htmlPage += "      <label for='relay4'>";
  htmlPage += "        <span class='off-span'>OFF</span>";
  htmlPage += "        <input type='range' name='relay4' id='relay4' min='0' max='1'";
  htmlPage += "value='" + String(digitalRead(relay4)) + "'/>";
  htmlPage += "        <span class='on-span'>ON</span>";
  htmlPage += "      </label>";

  htmlPage += "      <h3>Load 5</h3>";
  htmlPage += "      <label for='relay5'>";
  htmlPage += "        <span class='off-span'>OFF</span>";
  htmlPage += "        <input type='range' name='relay5' id='relay5' min='0' max='1'";
  htmlPage += "value='" + String(digitalRead(relay5)) + "'/>";
  htmlPage += "        <span class='on-span'>ON</span>";
  htmlPage += "      </label>";
  htmlPage += "      <button type='submit' class='submit-button' >Submit</button>";
  htmlPage += "    </form>";

  htmlPage += "    <script>";

  htmlPage += "      function handleEvent(event) {";
  htmlPage += "        event.preventDefault()";
  htmlPage += "      }";

  htmlPage += "      const form = document.getElementById('form-control')";
  htmlPage += "      form.addEventListener('submit',(event)=> handleEvent(event));";
  htmlPage += "    </script>";
  htmlPage += "  </body>";
  htmlPage += "</html>";

  return htmlPage;

}