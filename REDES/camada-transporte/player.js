 
// player.js
const WebSocket = require('ws');
const readline = require('readline');

const uri = 'ws://200.128.137.25:8765'; // Substitua pelo IP correto
const ws = new WebSocket(uri);

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

ws.on('open', () => {
    console.log("Conectado ao servidor.");

    // Lê entrada do usuário e envia
    rl.on('line', (input) => {
        ws.send(input);
    });
});

ws.on('message', (data) => {
    console.log(`\n${data}`);
});

ws.on('close', () => {
    console.log("Conexão encerrada pelo servidor.");
    rl.close();
});

ws.on('error', (err) => {
    console.error("Erro:", err.message);
});
