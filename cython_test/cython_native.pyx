from asyncio import Future

cdef extern int printf(const char *format, ...)


async def sum(long a, long b):
    f = Future()
    f.set_result(a + b)
    return await f


cpdef object sum_native(long a, long b):
    f = Future()
    cdef long result = a + b
    printf("From C: %ld\n", result)
    f.set_result(result)
    return f
