# servidor_jogo.py (sem mudança)
import asyncio
import websockets

clients = []

async def repassador(websocket):
    if len(clients) >= 2:
        await websocket.send("Servidor cheio. Aguarde.")
        return

    clients.append(websocket)
    jogador_id = len(clients)
    print(f"Jogador {jogador_id} conectado.")

    try:
        await websocket.send(f"Você é o Jogador {jogador_id}")
        while True:
            msg = await websocket.recv()
            print(f"Jogador {jogador_id} disse: {msg}")

            for client in clients:
                if client != websocket:
                    await client.send(f"Jogador {jogador_id}: {msg}")

    except websockets.ConnectionClosed as ex:
        print(f"Jogador {jogador_id} desconectado.")
        print(f"{ex!r}")
    finally:
        clients.remove(websocket)

async def main():
    print("Servidor aguardando conexões em ws://0.0.0.0:8765")
    async with websockets.serve(repassador, "0.0.0.0", 8765, open_timeout=None, ping_interval=None, ping_timeout=None, close_timeout=None):
        await asyncio.Future()

asyncio.run(main())