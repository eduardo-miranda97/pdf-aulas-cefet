# Problemas de Otimização Multiobjetivo

---

## 1. Seleção de Projetos

### Descrição

Uma organização possui vários projetos candidatos. Cada projeto possui custo, lucro, impacto social e risco. Deve-se selecionar um conjunto de projetos para execução.

### Variáveis de decisão

Para cada projeto `i`:

- `x_i = 1`: projeto selecionado;
- `x_i = 0`: projeto não selecionado.

### Objetivos

- **Maximizar o lucro total**:

  `f1(x) = Σ lucro_i x_i`

- **Maximizar o impacto social**:

  `f2(x) = Σ impacto_i x_i`

- **Minimizar o risco total**:

  `f3(x) = Σ risco_i x_i`

### Restrições

- Orçamento máximo:

  `Σ custo_i x_i <= orçamento`

- Recursos disponíveis podem limitar a quantidade ou combinação de projetos.

- Alguns projetos podem possuir dependências. Por exemplo, o projeto B só pode ser selecionado se A também for selecionado:

  `x_B <= x_A`

- `x_i ∈ {0,1}`.

---

## 2. Seleção de Características para Machine Learning

### Descrição

Dado um conjunto de características (features), selecionar um subconjunto que produza um modelo preditivo eficiente.

### Variáveis de decisão

Para cada feature `i`:

- `x_i = 1`: feature utilizada;
- `x_i = 0`: feature descartada.

### Objetivos

- **Minimizar o erro de classificação/regressão**:

  `f1(x) = erro(x)`

- **Minimizar o número de características utilizadas**:

  `f2(x) = Σ x_i`

Opcionalmente:

- minimizar tempo de treinamento;
- minimizar memória utilizada pelo modelo.

### Restrições

- Pode ser exigido um número mínimo de características:

  `Σ x_i >= k_min`

- Algumas features podem ser mutuamente incompatíveis.

- Algumas features podem precisar ser selecionadas em conjunto.

---

## 3. Escalonamento de Tarefas

### Descrição

Um conjunto de tarefas deve ser distribuído entre máquinas ou processadores.

Cada tarefa possui tempo de execução, consumo energético e prazo.

### Variáveis de decisão

Para cada tarefa:

- máquina responsável;
- eventualmente, ordem de execução.

### Objetivos

- **Minimizar o makespan**:

  `f1(x) = C_max`

- **Minimizar o consumo energético**:

  `f2(x) = energia(x)`

- **Minimizar atrasos**:

  `f3(x) = Σ atraso_i`

### Restrições

- Cada tarefa deve ser executada por exatamente uma máquina.
- Uma máquina não pode executar duas tarefas simultaneamente, quando as tarefas não podem ser paralelizadas.
- Respeitar precedências:

  `início_j >= fim_i`

  quando `i` deve terminar antes de `j`.
- Respeitar prazos, caso sejam tratados como restrições duras.
- Limites de capacidade das máquinas.


## 4. Alocação de Salas e Horários

### Descrição

Alocar disciplinas em salas e horários, considerando capacidade das salas, disponibilidade de professores e conflitos entre disciplinas.

### Variáveis de decisão

Para cada disciplina:

- sala;
- horário.

### Objetivos

- **Minimizar conflitos**.
- **Minimizar deslocamentos dos alunos**.
- **Maximizar utilização das salas**.
- **Minimizar o número de salas utilizadas**.

### Restrições

- Uma sala não pode receber duas disciplinas simultaneamente.
- Um professor não pode ministrar duas disciplinas simultaneamente.
- Uma sala deve possuir capacidade suficiente:

  `capacidade_sala >= alunos_disciplina`

- Respeitar disponibilidade dos professores.
- Respeitar disponibilidade das salas.
- Disciplinas que possuem alunos em comum não podem ocorrer simultaneamente.


---

## 5. Localização de Instalações

### Descrição

Escolher locais para instalar hospitais, escolas, centros de distribuição, postos de atendimento ou outras instalações.

### Variáveis de decisão

Para cada possível local:

- `x_i = 1`: instalação construída;
- `x_i = 0`: instalação não construída.

Também pode haver uma variável indicando qual instalação atende cada usuário.

### Objetivos

- **Minimizar custo de instalação**:

  `f1(x) = Σ custo_i x_i`

- **Minimizar distância média dos usuários**.

- **Maximizar cobertura da população**.

Uma alternativa é minimizar a maior distância entre um usuário e a instalação que o atende.

### Restrições

- Orçamento máximo.
- Número mínimo ou máximo de instalações.
- Cada usuário deve ser atendido por pelo menos uma instalação.
- Capacidade máxima de atendimento de cada instalação.
- Algumas regiões podem ser proibidas para instalação.


## 6. Projeto de Rede de Computadores (Network Design)

### Descrição

Dado um conjunto de possíveis enlaces entre nós de uma rede, selecionar quais enlaces devem ser instalados.

### Variáveis de decisão

Para cada possível enlace `(i,j)`:

- `x_ij = 1`: enlace instalado;
- `x_ij = 0`: enlace não instalado.

### Objetivos

- **Minimizar o custo da infraestrutura**:

  `f1(x) = Σ custo_ij x_ij`

- **Minimizar a latência da rede**.

- **Maximizar a largura de banda disponível**.

- **Maximizar a confiabilidade**.

### Restrições

- A rede deve permanecer conectada.
- Limite máximo de orçamento.
- Capacidade mínima para determinados pares origem-destino.
- Pode existir limite no número de enlaces por nó.
- Pode ser exigida redundância para determinados nós.


---

## 7. Roteamento de Veículos Multiobjetivo (VRP)

### Descrição

Uma frota de veículos deve atender um conjunto de clientes, definindo as rotas de cada veículo.

### Objetivos

- **Minimizar a distância total percorrida**.
- **Minimizar o tempo total de viagem**.
- **Minimizar o custo operacional**.
- **Minimizar emissões de CO₂**.

Uma versão mais simples pode utilizar apenas dois objetivos:

`min distância`

`min custo`

### Restrições

- Todo cliente deve ser visitado.
- Cada cliente deve ser visitado exatamente uma vez.
- Cada rota deve começar e terminar no depósito.
- Capacidade dos veículos não pode ser excedida.
- Respeitar janelas de tempo, se utilizadas.
- Número máximo de veículos disponível.


---

## 8. Layout de Máquinas

### Descrição

Organizar máquinas em uma fábrica minimizando custos de movimentação e outros fatores relacionados ao layout.

### Variáveis de decisão

Posição de cada máquina na área disponível.

### Objetivos

- **Minimizar distância total de movimentação**.
- **Minimizar custo de transporte interno**.
- **Minimizar área ocupada**.
- **Maximizar segurança ou distância entre determinados equipamentos**.

### Restrições

- Duas máquinas não podem ocupar a mesma posição.
- Todas as máquinas devem estar dentro da área disponível.
- Respeitar dimensões das máquinas.
- Determinadas máquinas podem precisar ficar próximas.
- Outras máquinas podem precisar manter uma distância mínima.


---

## 10. Seleção de Saídas de Emergência / Evacuação

### Descrição

Dado um edifício ou rede de ambientes, escolher quais saídas de emergência devem ser instaladas.

Cada possível saída possui um custo de instalação. A escolha das saídas influencia as distâncias e os tempos de evacuação.

### Variáveis de decisão

Para cada possível saída `i`:

- `x_i = 1`: saída instalada;
- `x_i = 0`: saída não instalada.

### Objetivos

- **Minimizar o custo das saídas**:

  `f1(x) = Σ custo_i x_i`

- **Minimizar a distância média de evacuação**.

- **Minimizar a maior distância de evacuação**:

  `f3(x) = max distância_de_evacuação`

- **Maximizar a redundância/segurança**.

### Restrições

- Deve existir pelo menos uma saída.
- Determinadas regiões devem possuir uma saída a uma distância máxima.
- Pode existir um número máximo de saídas devido ao orçamento.
- Algumas saídas podem ser incompatíveis.
- Pode ser exigida uma quantidade mínima de rotas independentes para determinadas regiões.

### Representação sugerida

**Binária.**

### Observação

Esse problema permite criar instâncias pequenas, resolvíveis por força bruta, e instâncias grandes, adequadas para NSGA-II, SPEA2, MOEA/D e outros algoritmos.

---

# Sugestão de uso na disciplina

Uma possível sequência de dificuldade seria:

1. **Mochila Multiobjetivo** — introdução à otimização multiobjetivo.
2. **Seleção de Projetos** — problemas binários com restrições.
3. **Seleção de Features** — aplicação em Machine Learning.
4. **Escalonamento de Tarefas** — representação inteira/permutação.
5. **Alocação de Salas** — restrições complexas.
6. **Localização de Instalações** — problema de cobertura.
7. **Network Design** — grafos e conectividade.
8. **VRP Multiobjetivo** — problema avançado.
9. **Layout de Máquinas** — problema espacial.
10. **Evacuação** — aplicação integrada.

## Critérios que podem ser avaliados

Independentemente do problema, os alunos podem ser avaliados considerando:

- Implementação da representação da solução.
- Funções objetivo.
- Tratamento das restrições.
- Operadores de cruzamento e mutação.
- Implementação do algoritmo multiobjetivo.
- Qualidade da fronteira de Pareto.
- Diversidade das soluções.
- Tempo computacional.
- Comparação entre diferentes algoritmos.
- Análise das soluções obtidas.

## Métricas interessantes

Para comparar os algoritmos, podem ser utilizadas:

- **Hypervolume (HV)**;
- **Generational Distance (GD)**;
- **Inverted Generational Distance (IGD)**;
- **Spread / Diversity**;
- quantidade de soluções não dominadas;
- tempo de execução.

