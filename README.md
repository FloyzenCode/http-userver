# HTTP server using async framework userver

- Config & Build

```shell
mkdir build_release
cd build_release
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

if build successfull:
```shell
./service_template
```
if error type:
```shell
Unhandled exception in components::Run: Error while parsing configs from file 'config_dev.yaml'. Details: Cannot open config file 'config_dev.yaml'
```

in the arguments before running the executable file, specify the path to the static configuration in the parameters:
```shell
./service_template --config=../configs/static_config.yaml
```

to check functionality:
```shell
curl 127.0.0.1:8080/hello
```

if not build, try use Makefile.local.

- for MacOS:
```makefile
CMAKE_DEBUG_FLAGS =
CMAKE_COMMON_FLAGS += -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
-DUSERVER_NO_WERROR=1 -DUSERVER_CHECK_PACKAGE_VERSIONS=0 \
-DUSERVER_FEATURE_REDIS_HI_MALLOC=1 \
-DUSERVER_FEATURE_CRYPTOPP_BLAKE2=0 -DUSERVER_DOWNLOAD_PACKAGE_CRYPTOPP=1 \
-DUSERVER_FEATURE_CLICKHOUSE=0 \
-DUSERVER_FEATURE_RABBITMQ=0 \
-DOPENSSL_ROOT_DIR=$(brew --prefix openssl) \
-DUSERVER_PG_LIBRARY_DIR=$(pg_config --libdir) -DUSERVER_PG_INCLUDE_DIR=$(pg_config --includedir) \
-DUSERVER_PG_SERVER_LIBRARY_DIR=$(pg_config --pkglibdir) -DUSERVER_PG_SERVER_INCLUDE_DIR=$(pg_config --includedir-server)
```

- for Arch:
```makefile
CMAKE_COMMON_FLAGS += -DUSERVER_FEATURE_PATCH_LIBPQ=0
```

- for Ubuntu:
```makefile
CMAKE_COMMON_FLAGS += -DCMAKE_CXX_COMPILER=g++-8 -DCMAKE_C_COMPILER=gcc-8 -DUSERVER_FEATURE_CRYPTOPP_BLAKE2=0 \
  -DUSERVER_FEATURE_CRYPTOPP_BASE64_URL=0 -DUSERVER_FEATURE_GRPC=0 -DUSERVER_FEATURE_POSTGRESQL=0 \
  -DUSERVER_FEATURE_MONGODB=0 -DUSERVER_USE_LD=gold
```