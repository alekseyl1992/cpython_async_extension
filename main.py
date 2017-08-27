import asyncio
import native

async def print_sum(a, b):
    s = await native.sum(a, b)
    print('Result: {}'.format(s))

loop = asyncio.get_event_loop()
loop.run_until_complete(print_sum(2, 2))
loop.close()
