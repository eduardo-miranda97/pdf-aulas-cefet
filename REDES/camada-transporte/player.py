# jogador.py
import asyncio
import websockets
import threading

async def receber_msg(websocket):
    try:
        async for msg in websocket:
            print(f"\n{msg}")
    except websockets.ConnectionClosed:
        print("Conexão encerrada pelo servidor.")

async def enviar_msg(websocket):
    while True:
        msg = input("Você: ")
        await websocket.send(msg)

async def main():
    uri = "ws://192.168.2.111:8765"  # Substitua pelo IP correto!
    async with websockets.connect(uri) as websocket:
        print("Conectado ao servidor.")

        # Cria tarefas concorrentes para enviar e receber mensagens
        receber = asyncio.create_task(receber_msg(websocket))
        enviar = asyncio.create_task(enviar_msg(websocket))
        await asyncio.gather(receber, enviar)


asyncio.run(main())
