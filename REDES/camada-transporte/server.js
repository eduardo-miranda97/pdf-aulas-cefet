 
// server.js
const WebSocket = require('ws');

const wss = new WebSocket.Server({ port: 8765 });
const clients = [];

console.log("Servidor aguardando conexões em ws://0.0.0.0:8765");

wss.on('connection', (ws) => {
    if (clients.length >= 2) {
        ws.send("Servidor cheio. Aguarde.");
        ws.close();
        return;
    }

    clients.push(ws);
    const jogadorId = clients.length;
    console.log(`Jogador ${jogadorId} conectado.`);
    ws.send(`Você é o Jogador ${jogadorId}`);

    ws.on('message', (message) => {
        console.log(`Jogador ${jogadorId} disse: ${message}`);
        clients.forEach(client => {
            if (client !== ws && client.readyState === WebSocket.OPEN) {
                client.send(`Jogador ${jogadorId}: ${message}`);
            }
        });
    });

    ws.on('close', () => {
        console.log(`Jogador ${jogadorId} desconectado.`);
        const index = clients.indexOf(ws);
        if (index > -1) clients.splice(index, 1);
    });

    ws.on('error', (err) => {
        console.error(`Erro do Jogador ${jogadorId}:`, err.message);
    });
});
