# Trabalho de Matematica Computacional - Analise e Desenvolvimento de Sistemas UNINTER
# Pablo dos Santos Garajau - RU : 3560344

def criptografar(palavra, chave):
    vet_frase_criptografada = []
    cont = 0

    print("Mensagem criptografada: ")
    for i in palavra:
        crip_frase = ord(i)
        # metodo
        crip_chave = ord(chave[cont % len(chave)])
        const = crip_frase ^ crip_chave
        # armazenando cada letra criptgrafada em um vetor
        vet_frase_criptografada.append(const)
        cont += 1
        print(i, ":", const)
    print()

    return vet_frase_criptografada

def descriptografar(frase_criptografada, chave):
    print("Mensagem decriptografada: ")
    for i in frase_criptografada:
        print(str(i^chave))

palavra = 'AMOR'
chave = '33'

criptografia = criptografar(palavra, chave)
descriptografar(criptografia, chave) 