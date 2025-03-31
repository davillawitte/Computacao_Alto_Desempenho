# 🚀 Cache e Acesso à Memória
Os processadores modernos possuem uma hierarquia de memória para otimizar a velocidade de acesso aos dados:

Cache L1 (nível 1): Pequena (32KB–128KB por núcleo), mas extremamente rápida.

Cache L2 (nível 2): Maior (256KB–2MB por núcleo), um pouco mais lenta que L1.

Cache L3 (nível 3): Compartilhada entre os núcleos, ainda maior, mas mais lenta que L2.

Memória RAM: Muito maior (~GBs), mas muito mais lenta que as caches.

A ideia principal do cache é armazenar dados frequentemente acessados para evitar leituras lentas da RAM. No entanto, quando os dados necessários não estão no cache, ocorre um cache miss, e o processador precisa buscar os dados na RAM, o que é centenas de vezes mais lento.

# 📌 Por que a ordem de acesso (linha x coluna) importa?
A memória RAM e os caches armazenam matrizes em ordem de linha (row-major order). Ou seja, uma matriz
𝑀
×
𝑁
M×N é armazenada como uma sequência de linhas contínuas na memória.

##🔵 Acesso por Linhas (Row-Major Order)

```
for (int i = 0; i < size; i++) {
for (int j = 0; j < size; j++) {
result[i] += matrix[i][j] \* vector[j];
}
}
```

O acesso percorre a matriz linha a linha.

Como os elementos da mesma linha estão próximos na memória, eles são carregados na cache de forma eficiente.

Poucos cache misses, pois o processador já preenche os blocos de cache com valores adjacentes.

# ➡ Resultado: Melhor uso da cache, execução mais rápida.

## 🔴 Acesso por Colunas (Column-Major Order)

```
for (int j = 0; j < size; j++) {
for (int i = 0; i < size; i++) {
result[i] += matrix[i][j] \* vector[j];
}
}
```

O acesso percorre a matriz coluna por coluna.

Como os elementos da mesma coluna não estão armazenados juntos na memória, cada acesso a matrix[i][j] pode exigir um novo carregamento na cache, causando muitos cache misses.

Isso gera acessos frequentes à memória RAM, que é muito mais lenta que a cache.

# ➡ Resultado: Desempenho degradado à medida que o tamanho da matriz cresce.

📊 O Impacto no Desempenho
Para matrizes pequenas, tudo cabe na cache L1 ou L2, então a diferença de tempo entre as abordagens é pequena.

Para matrizes grandes (que ultrapassam a cache L1 e L2), a abordagem por colunas sofre penalizações severas porque causa mais acessos à RAM, que são muito mais lentos.

O ponto exato onde a diferença de tempo se torna significativa depende do tamanho do cache do processador em uso.

## 🔹 Exemplo prático:
Se sua CPU tiver uma cache L1 de 256KB e cada número double ocupar 8 bytes, então:

Uma matriz 200x200 ocupa 320KB (200×200×8 bytes), que já ultrapassa a cache L1.

Para 500x500 (2MB), já pode começar a ultrapassar até mesmo a cache L2.

# 🔥 Resumo
Acesso por linhas → Melhor aproveitamento da cache → Menos cache misses → Execução mais rápida.

Acesso por colunas → Pior aproveitamento da cache → Muitos cache misses → Mais acessos à RAM → Execução mais lenta.

Quando a matriz cresce e ultrapassa o tamanho da cache L1/L2, a diferença de tempo se torna evidente.
