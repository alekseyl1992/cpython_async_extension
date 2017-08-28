import asyncio
import cython_native

async def print_sum(a, b):
    s = await cython_native.sum_native(a, b)
    print('Result: {}'.format(s))

loop = asyncio.get_event_loop()
loop.run_until_complete(print_sum(2, 2))
loop.close()
