FROM ubuntu:22.04 AS builder

# ДОБАВЛЕНО: git необходим для скачивания Google Test через FetchContent
RUN apt-get update && apt-get install -y cmake g++ git && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY . .

# Собираем весь проект (включая тесты)
RUN cmake -B build -DCMAKE_BUILD_TYPE=Release && cmake --build build

FROM ubuntu:22.04
WORKDIR /app

# Копируем только готовый исполняемый файл из этапа builder
COPY --from=builder /app/build/matrix_calculator .

CMD ["./matrix_calculator"]