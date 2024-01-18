# Start via `make test-debug` or `make test-release`
async def test_hello_base(service_client):
    response = await service_client.get('/hello')
    assert response.status == 200
    assert response.content == b'Hello world!\n'
    assert 'X-RequestId' not in response.headers.keys(), 'Unexpected header'