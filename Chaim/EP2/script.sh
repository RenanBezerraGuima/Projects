#!/bin/bash

programa="./14605640.exe"
pastaEntrada="./testesEntrada"
pastaSaida="./testesSaida"

for arquivoEntrada in "$pastaEntrada"/*; do
    nomeArquivo=$(basename "$arquivoEntrada")
    arquivoSaida="$pastaSaida/${nomeArquivo%.*}.dat.out"
    arquivoTemporario=$(mktemp)

    $programa < "$arquivoEntrada" > "$arquivoTemporario"

    diffOutput=$(diff "$arquivoTemporario" "$arquivoSaida")

    if [ -z "$diffOutput" ]; then
        echo "Resultado correto para $nomeArquivo"
    else
        echo "Resultado incorreto para $nomeArquivo"
        echo "$diffOutput"
    fi

    rm "$arquivoTemporario"
done
