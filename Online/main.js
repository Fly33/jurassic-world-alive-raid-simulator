// Function to save data to local storage
function saveToLocalStorage(data) {
  try {
      const jsonData = JSON.stringify(data);
      localStorage.setItem(location.pathname, jsonData);
  } catch (error) {
      console.error('Error saving to local storage', error);
  }
}

// Function to load data from local storage
function loadFromLocalStorage() {
  try {
      const jsonData = localStorage.getItem(location.pathname);
      return jsonData ? JSON.parse(jsonData) : null;
  } catch (error) {
      console.error('Error loading from local storage', error);
      return null;
  }
}

function encodeData(data) {
    // Сериализуем объект в строку JSON
    const serializedData = JSON.stringify(data);

    // Ваш код сжатия данных (например, zlib)

    // Кодируем данные в base64
    const base64Data = btoa(serializedData);

    // Проверяем, чтобы строка base64 не содержала символов, которые могут нарушить URL
    const safeBase64Data = base64Data.replace(/\+/g, '-').replace(/\//g, '_').replace(/=+$/, '');

    return safeBase64Data;
}

function decodeData(base64Data) {
    // Заменяем символы '-' на '+', а '_' на '/'
    const base64Standard = base64Data.replace(/-/g, '+').replace(/_/g, '/');

    // Добавляем необходимые символы для дополнения до стандартной длины Base64, если нужно
    const paddingLength = (4 - (base64Standard.length % 4)) % 4;
    const paddedBase64 = base64Standard + '='.repeat(paddingLength);

    // Декодируем Base64 в исходные данные
    const decodedData = atob(paddedBase64);

    // Распарсим JSON
    const originalData = JSON.parse(decodedData);

    return originalData;
}

function escapeHTML(str) {
    return str.replace(/&/g, "&amp;")
              .replace(/</g, "&lt;")
              .replace(/>/g, "&gt;")
              .replace(/"/g, "&quot;")
              .replace(/'/g, "&#039;");
}

async function writeClipboardText(text) {
  try {
    await navigator.clipboard.writeText(text);
  } catch (error) {
    console.error(error.message);
  }
}

window.onload = function() {
// Загрузка файла data.json
fetch('data.json')
  .then(response => response.json())
  .then(dataReady)
  .catch(error => {
    console.error('Ошибка при загрузке файла:', error);
  });
};

// Ваша функция, которую нужно вызвать
function dataReady(dino_data) {
    let boss = {};
    let dino = {};
    let data = loadFromLocalStorage() || {
        current_strategy_id: undefined,
        new_strategy_id: 1,
        strategy: {},
    };
    
    function newStrategy(data) {
        let strategy_id = data.new_strategy_id++;
        let strategy = {
            strategy_id: strategy_id,
            name: `Strategy #${strategy_id}`,
            boss: {},
            team: [
                {},
                {},
                {},
                {},
            ],
            turn: [
                [0, 0, 0, 0],
            ],
            method: 'check',
        };
        data.strategy[strategy_id] = strategy;
        return strategy_id;
    }

    const urlParams = new URLSearchParams(window.location.search);
    console.log(urlParams);
    if (urlParams.has("data")) {
        const dataValue = urlParams.get("data");
        urlParams.delete("data");
        const updatedUrl = `${window.location.origin}${window.location.pathname}?${urlParams.toString()}`;
        window.history.replaceState({}, document.title, updatedUrl);

        let strategy = decodeData(dataValue);
        let strategy_id = data.new_strategy_id++;
        strategy.strategy_id = strategy_id;
        strategy.name += " (imported)";
        data.strategy[strategy_id] = strategy;
        data.current_strategy_id = strategy_id;
        saveToLocalStorage(data);
    }
  
    if (Object.keys(data.strategy).length === 0) {
        data.current_strategy_id = newStrategy(data);
        saveToLocalStorage(data);
    }

    const strategySelect = document.getElementById("strategy");
    strategySelect.addEventListener('change', function() {
        data.current_strategy_id = this.options[this.selectedIndex].value;
        saveToLocalStorage(data);
        loadStrategy(data.strategy[data.current_strategy_id]);
    });


    function updateStrategySelect() {
        strategySelect.innerHTML = "";
        let selected_index;
        Object.keys(data.strategy).sort((i, j) => data.strategy[i].name.localeCompare(data.strategy[j].name)).forEach((strategy_id, index) => { 
            const option = document.createElement('option');
            option.value = strategy_id;
            option.textContent = data.strategy[strategy_id].name;
            strategySelect.appendChild(option);
            if (strategy_id == data.current_strategy_id)
                strategySelect.selectedIndex = index;
        });
    }
    
    function strategyToText(strategy) {
        let result = "";
        let n = 0; 
        if (!strategy.boss.paleo_id)
            return "";
        strategy.team.forEach((member, index) => {
            if (member.paleo_id)
                ++n;
        });
        if (n === 0)
            return "";
        result += `${boss[strategy.boss.paleo_id].jwacalc_id}\n`;
        result += `${n} 0\n`;
        strategy.team.forEach((member, index) => {
            if (!member.paleo_id)
                return;
            result += `${dino[member.paleo_id].jwacalc_id} ${member.level} ${member.health} ${member.damage} ${member.speed}`;
            if (dino[member.paleo_id].raryty === "omega")
                result += `${member.omega_health} ${member.omega_damage} ${member.omega_speed} ${member.omega_armor} ${member.omega_crit_chance} ${member.omega_crit_factor}`;
            result += '\n';
        });
        strategy.turn.forEach((turn) => {
            strategy.team.forEach((member, index) => {
                if (!member.paleo_id)
                    return;
                result += `${turn[index]} `;
            });
            result += '\n';
        });
        return result;
    }

    dino_data.boss.forEach((_boss, index) => {
      boss[_boss.paleo_id] = _boss;
      _boss.index = index;
    });

    dino_data.dino.forEach((_dino, index) => {
      dino[_dino.paleo_id] = _dino;
      _dino.index = index;
    });

    // Получаем ссылку на элемент <select>
    const bossDialog = document.getElementById('bossDialog');
    const bossSelect = bossDialog.querySelector('select.boss');
    const bossDialogElement = bossDialog.querySelector('div.boss');
    const bossDialogOkButton = bossDialog.querySelector('button.ok');
    const bossDialogCancelButton = bossDialog.querySelector('button.cancel');

    // Проходим по списку боссов и добавляем их в <select>
    dino_data.boss.forEach(boss => {
        const option = document.createElement('option');
        option.value = boss.paleo_id;
        option.textContent = boss.name;
        bossSelect.appendChild(option);
    });

    // Добавляем обработчик события 'change'
    bossSelect.addEventListener('change', function() {
        // Получаем выбранный пункт
        const paleo_id = bossSelect.options[bossSelect.selectedIndex].value;
        updateBossImage(bossDialogElement, paleo_id);
    });
    
    bossDialogOkButton.addEventListener('click', function() {
        const paleo_id = bossSelect.options[bossSelect.selectedIndex].value;
        data.strategy[data.current_strategy_id].boss.paleo_id = paleo_id;
        saveToLocalStorage(data);
        updateBossImage(bossElement, paleo_id);
        bossDialog.close();
    });
    bossDialogCancelButton.addEventListener('click', function() {
        bossDialog.close();
    });
    
    function updateBossImage(bossElement, paleo_id) {
        const bossImage = bossElement.querySelector(`img.creature.boss`);
        const minionImage = bossElement.querySelectorAll(`img.creature.minion`);
        if (paleo_id) {
            bossImage.src = `https://cdn.paleo.gg/games/jwa/images/creature/${paleo_id}.png`;
        } else {
            bossImage.src = 'creature.png';
        }    
        if (paleo_id && boss[paleo_id].minions.length) {
            minionImage.forEach((image, index) => {
                image.src = `https://cdn.paleo.gg/games/jwa/images/creature/${boss[paleo_id].minions[index].paleo_id}.png`;
                image.style.display = 'inline-block';
            });
        } else {
            minionImage.forEach((image) => {
                image.src = 'creature.png';
                image.style.display = 'none';
            });
        }
    }
    
    const bossElement = document.querySelector('#boss div.boss');
    
    bossElement.querySelector(`img.creature.boss`).addEventListener('click', function() {
        let paleo_id = data.strategy[data.current_strategy_id].boss.paleo_id;
        if (paleo_id in boss)
            bossSelect.selectedIndex = boss[paleo_id].index + 1;
        else
            bossSelect.selectedIndex = 0;
        const event = new Event('change', { bubbles: true });
        bossSelect.dispatchEvent(event);
        bossDialog.showModal();
    });

    function updateDinoImage(image, paleo_id) {
        if (paleo_id) {
            image.src = `https://cdn.paleo.gg/games/jwa/images/creature/${paleo_id}.png`;
        } else {
            image.src = 'creature.png';
        }
    }

    function updateAbilityImage(abilityElement, paleo_id, ability_index) {
        const imageElement = abilityElement.querySelector('img.ability');
        const priorityElement = abilityElement.querySelector('img.priority');
        const actlastElement = abilityElement.querySelector('img.act-last');
        const preciseElement = abilityElement.querySelector('img.precise');
        const alertElement = abilityElement.querySelector('img.alert');
        const revengeElement = abilityElement.querySelector('img.revenge');

        if (paleo_id in dino && ability_index) {
            const imageUrl = `https://cdn.paleo.gg/games${dino[paleo_id].abilities[ability_index-1].icon}`;
            imageElement.src = imageUrl;
            if (dino[paleo_id].abilities[ability_index-1].priority == 1)
              priorityElement.style.removeProperty('display');
            else
              priorityElement.style.display = 'none';
            if (dino[paleo_id].abilities[ability_index-1].priority == -1)
              actlastElement.style.removeProperty('display');
            else
              actlastElement.style.display = 'none';
            if (dino[paleo_id].abilities[ability_index-1].precise)
              preciseElement.style.removeProperty('display');
            else
              preciseElement.style.display = 'none';
            if (dino[paleo_id].abilities[ability_index-1].alert)
              alertElement.style.removeProperty('display');
            else
              alertElement.style.display = 'none';
            if (dino[paleo_id].abilities[ability_index-1].revenge)
              revengeElement.style.removeProperty('display');
            else
              revengeElement.style.display = 'none';
        } else {
            imageElement.src = 'ability.png';
            priorityElement.style.display = 'none';
            actlastElement.style.display = 'none';
            preciseElement.style.display = 'none';
            alertElement.style.display = 'none';
            revengeElement.style.display = 'none';
        }
    }

    const dinoDialog = document.getElementById('dinoDialog');
    const dinoDialogSelect = dinoDialog.querySelector('select.creature');
    const dinoDialogImage = dinoDialog.querySelector('img.creature');
    const dinoDialogOkButton = dinoDialog.querySelector('button.ok');
    const dinoDialogCancelButton = dinoDialog.querySelector('button.cancel');
    dino_data.dino.forEach((dino) => {
        const option = document.createElement("option");
        option.value = dino.paleo_id;
        option.textContent = dino.name;
        dinoDialogSelect.appendChild(option);
    });
    
    dinoDialogSelect.addEventListener('change', function() {
        // Получаем список способностей для выбранного динозавра
        const paleo_id = this.options[this.selectedIndex].value;
        const omegaParams = dinoDialog.querySelector('div.omega');
        if (paleo_id in dino && dino[paleo_id].rarity == "omega") {
            omegaParams.style.removeProperty('display');
        } else {
            omegaParams.style.display = 'none';
        }

        updateDinoImage(dinoDialogImage, paleo_id);
    });

    // Найти все элементы select с классом "team"
    const dinoImage = document.querySelectorAll("img.team");

    dinoImage.forEach((image, dino_index) => {
        image.addEventListener('click', function() {
            var dinoDialogOkButtonClick = function() {
                let paleo_id = dinoDialogSelect.options[dinoDialogSelect.selectedIndex].value;
                let dino_params = {
                    paleo_id: paleo_id,
                    level: parseInt(dinoDialog.querySelector('input.level').value),
                    health: parseInt(dinoDialog.querySelector('input.health').value),
                    damage: parseInt(dinoDialog.querySelector('input.damage').value),
                    speed: parseInt(dinoDialog.querySelector('input.speed').value),
                };
                if (paleo_id in dino && dino[paleo_id].rarity == "omega") {
                    dino_params.omega_health = parseInt(dinoDialog.querySelector('input.omega_health').value);
                    dino_params.omega_damage = parseInt(dinoDialog.querySelector('input.omega_damage').value);
                    dino_params.omega_speed = parseInt(dinoDialog.querySelector('input.omega_speed').value);
                    dino_params.omega_armor = parseInt(dinoDialog.querySelector('input.omega_armor').value);
                    dino_params.omega_crit_chance = parseInt(dinoDialog.querySelector('input.omega_crit_chance').value);
                    dino_params.omega_crit_factor = parseInt(dinoDialog.querySelector('input.omega_crit_factor').value);
                }
                if (data.strategy[data.current_strategy_id].team[dino_index].paleo_id != paleo_id) {
                    updateDinoImage(image, paleo_id);
                    const turnElements = abilitiesContainer.querySelectorAll('div.turn');
                    data.strategy[data.current_strategy_id].turn.forEach((turn, turn_index) => {
                        turn[dino_index] = 0;
                        const abilityElement = turnElements[turn_index].querySelectorAll('div.ability')[dino_index];
                        updateAbilityImage(abilityElement, paleo_id, 0);
                    })
                }
                data.strategy[data.current_strategy_id].team[dino_index] = dino_params;
                saveToLocalStorage(data);
                dinoDialogCancelButtonClick();
            }
            var dinoDialogCancelButtonClick = function() {
                dinoDialogOkButton.removeEventListener('click', dinoDialogOkButtonClick);
                dinoDialogCancelButton.removeEventListener('click', dinoDialogCancelButtonClick);
                dinoDialog.close();
            }
            dinoDialogOkButton.addEventListener('click', dinoDialogOkButtonClick);
            dinoDialogCancelButton.addEventListener('click', dinoDialogCancelButtonClick);

            let paleo_id = data.strategy[data.current_strategy_id].team[dino_index].paleo_id;
            if (paleo_id in dino)
                dinoDialogSelect.selectedIndex = dino[paleo_id].index + 1;
            else
                dinoDialogSelect.selectedIndex = 0;
            const event = new Event('change', { bubbles: true });
            dinoDialogSelect.dispatchEvent(event);

            dinoDialog.querySelector('input.level').value = data.strategy[data.current_strategy_id].team[dino_index].level || 0;
            dinoDialog.querySelector('input.health').value = data.strategy[data.current_strategy_id].team[dino_index].health || 0;
            dinoDialog.querySelector('input.damage').value = data.strategy[data.current_strategy_id].team[dino_index].damage || 0;
            dinoDialog.querySelector('input.speed').value = data.strategy[data.current_strategy_id].team[dino_index].speed || 0;

            dinoDialog.querySelector('input.omega_health').value = data.strategy[data.current_strategy_id].team[dino_index].omega_health || 0;
            dinoDialog.querySelector('input.omega_damage').value = data.strategy[data.current_strategy_id].team[dino_index].omega_damage || 0;
            dinoDialog.querySelector('input.omega_speed').value = data.strategy[data.current_strategy_id].team[dino_index].omega_speed || 0;
            dinoDialog.querySelector('input.omega_armor').value = data.strategy[data.current_strategy_id].team[dino_index].omega_armor || 0;
            dinoDialog.querySelector('input.omega_crit_chance').value = data.strategy[data.current_strategy_id].team[dino_index].omega_crit_chance || 0;
            dinoDialog.querySelector('input.omega_crit_factor').value = data.strategy[data.current_strategy_id].team[dino_index].omega_crit_factor || 0;
            
            dinoDialog.showModal();
        });
    });
    
    const abilityDialog = document.getElementById('abilityDialog');
    const abilityDialogSelect = abilityDialog.querySelector('select.ability');
    const abilityDialogElement = abilityDialog.querySelector('div.ability');
    const abilityDialogOkButton = abilityDialog.querySelector('button.ok');
    const abilityDialogCancelButton = abilityDialog.querySelector('button.cancel');

    function initTurn(turnElement, turn_index) {
        const abilityElements = turnElement.querySelectorAll('div.ability');
        abilityElements.forEach((ability, dino_index) => {
            updateAbilityImage(ability, data.strategy[data.current_strategy_id].team[dino_index].paleo_id, data.strategy[data.current_strategy_id].turn[turn_index][dino_index]);
            
            ability.addEventListener('click', function() {
                var abilityDialogSelectChange = function() {
                    const paleo_id = data.strategy[data.current_strategy_id].team[dino_index].paleo_id;
                    let ability_index = +abilityDialogSelect[abilityDialogSelect.selectedIndex].value;
                    updateAbilityImage(abilityDialogElement, paleo_id, ability_index);
                }
                var abilityDialogOkButtonClick = function() {
                    const paleo_id = data.strategy[data.current_strategy_id].team[dino_index].paleo_id;
                    let ability_index = +abilityDialogSelect[abilityDialogSelect.selectedIndex].value;
                    
                    data.strategy[data.current_strategy_id].turn[turn_index][dino_index] = ability_index;
                    saveToLocalStorage(data);
                    
                    updateAbilityImage(ability, paleo_id, ability_index);

                    abilityDialogCancelButtonClick();
                }
                var abilityDialogCancelButtonClick = function() {
                    abilityDialogSelect.removeEventListener('change', abilityDialogSelectChange);
                    abilityDialogOkButton.removeEventListener('click', abilityDialogOkButtonClick);
                    abilityDialogCancelButton.removeEventListener('click', abilityDialogCancelButtonClick);                    
                    abilityDialog.close();
                }
                abilityDialogSelect.addEventListener('change', abilityDialogSelectChange);
                abilityDialogOkButton.addEventListener('click', abilityDialogOkButtonClick);
                abilityDialogCancelButton.addEventListener('click', abilityDialogCancelButtonClick);

                while (abilityDialogSelect.options.length > 1) {
                    abilityDialogSelect.remove(1);
                }

                let paleo_id = data.strategy[data.current_strategy_id].team[dino_index].paleo_id;

                if (paleo_id in dino) {
                    const abilities = dino[paleo_id].abilities;

                    abilities.forEach((ability, index) => {
                        const option = document.createElement('option');
                        option.value = index + 1;
                        option.textContent = ability.name;
                        abilityDialogSelect.appendChild(option.cloneNode(true));
                    });
                    
                    abilityDialogSelect.selectedIndex = data.strategy[data.current_strategy_id].turn[turn_index][dino_index];
                    const event = new Event('change', { bubbles: true });
                    abilityDialogSelect.dispatchEvent(event);

                    abilityDialog.showModal();
                }
            });
        });
    }
    
    function updateTurn(turnElement, turn_index) {
        const abilityElements = turnElement.querySelectorAll('div.ability');
        abilityElements.forEach((ability, dino_index) => {
            updateAbilityImage(ability, data.strategy[data.current_strategy_id].team[dino_index].paleo_id, data.strategy[data.current_strategy_id].turn[turn_index][dino_index]);
        })
    }

    const abilitiesContainer = document.getElementById('abilities-container');
    const firstTurn = abilitiesContainer.querySelector('div.turn:first-child');
    
    const addButton = document.getElementById('add');

    addButton.addEventListener('click', function() {
      const newTurn = firstTurn.cloneNode(true);
      
      const turn_index = data.strategy[data.current_strategy_id].turn.length;
      
      data.strategy[data.current_strategy_id].turn.push([0, 0, 0, 0]);
      saveToLocalStorage(data);

      initTurn(newTurn, turn_index);
      
      // Добавляем копию в конец контейнера
      abilitiesContainer.appendChild(newTurn);
    });

    const removeButton = document.getElementById('remove');

    removeButton.addEventListener('click', function() {
      if (data.strategy[data.current_strategy_id].turn.length >= 2) {
        data.strategy[data.current_strategy_id].turn.pop();
        saveToLocalStorage(data);
        const lastTurn = abilitiesContainer.querySelector('div.turn:last-child');
        abilitiesContainer.removeChild(lastTurn);
      }
    });
    
    const strategyDialog = document.getElementById('strategyDialog');
    const strategyTitle = strategyDialog.querySelector('input.title');
    const linkStrategyButton = strategyDialog.querySelector('button.link');
    const newStrategyButton = strategyDialog.querySelector('button.new');
    const duplicateStrategyButton = strategyDialog.querySelector('button.duplicate');
    const deleteStrategyButton = strategyDialog.querySelector('button.delete');
    const okStrategyButton = strategyDialog.querySelector('button.ok');
    const cancelStrategyButton = strategyDialog.querySelector('button.cancel');
    
    const menuButton = document.getElementById('menu');
    menuButton.addEventListener('click', function() {
        strategyTitle.value = data.strategy[data.current_strategy_id].name;
        strategyDialog.showModal();
    });

    linkStrategyButton.addEventListener('click', function() {
        let dataValue = encodeData(data.strategy[data.current_strategy_id]);
        let url = `http://fly33.github.io/jwa_raid/?data=${dataValue}`;
        writeClipboardText(url);
    });
    
    newStrategyButton.addEventListener('click', function() {
        strategyDialog.close();
        data.current_strategy_id = newStrategy(data);
        saveToLocalStorage(data);
        updateStrategySelect();
        loadStrategy(data.strategy[data.current_strategy_id]);
    });
    
    duplicateStrategyButton.addEventListener('click', function() {
        strategyDialog.close();
        let strategy_id = data.new_strategy_id++;
        let strategy = structuredClone(data.strategy[data.current_strategy_id]);
        strategy.strategy_id = strategy_id;
        strategy.name += " (copy)";
        data.strategy[strategy_id] = strategy;
        data.current_strategy_id = strategy_id;
        saveToLocalStorage(data);
        updateStrategySelect();
        loadStrategy(data.strategy[data.current_strategy_id]);
    });

    deleteStrategyButton.addEventListener('click', function() {
        if (!confirm("Delete the strategy?"))
            return;
        strategyDialog.close();
        let name = data.strategy[data.current_strategy_id].name;
        delete data.strategy[data.current_strategy_id];
        if (Object.keys(data.strategy).length === 0) {
            data.current_strategy_id = newStrategy(data);
        } else {
            let keys = Object.keys(data.strategy).sort((i, j) => data.strategy[i].name.localeCompare(data.strategy[j].name));
            data.current_strategy_id = keys.find((i) => name <= data.strategy[i].name) || keys[keys.length-1];
        }
        saveToLocalStorage(data);
        updateStrategySelect();
        loadStrategy(data.strategy[data.current_strategy_id]);
    });

    okStrategyButton.addEventListener('click', function() {
        data.strategy[data.current_strategy_id].name = strategyTitle.value;
        saveToLocalStorage(data);
        updateStrategySelect();
        loadStrategy(data.strategy[data.current_strategy_id]);
        strategyDialog.close();
    });
    
    cancelStrategyButton.addEventListener('click', function() {
        strategyDialog.close();
    });

    const selectMethod = document.querySelector('select.method');
    selectMethod.addEventListener('change', function() {
        data.strategy[data.current_strategy_id].method = this.options[this.selectedIndex].value;
        saveToLocalStorage(data);
    });

    let worker;

    const consoleElement = document.getElementById('console');
    const runButton = document.querySelector('button.run');
    
    function start(input, method) {
        runButton.innerHTML = 'Stop';
        consoleElement.innerHTML = '';

        const method_map = {
            'check': '--check',
            'explain_defeat': '--explain',
            'explain_win': '--explain --win',
            'chance': '--chance',
            'search_rand': '--search --method random',
            'search_full': '--search --method full',
            'help': '--help check',
            'version': '--version',
        };

        let method_args = method_map[method];
                            
        worker = new Worker('worker.js');
      
        // Обработчик сообщений от Web Worker
        worker.onmessage = (event) => {
            const result = event.data;
            if (result.type == "output") {
                consoleElement.innerHTML += escapeHTML(result.data) + "\n";
            } else if (result.type == "done") {
                stop();
            }
        };
        
        worker.postMessage({
            commandLine: `JWAcalc ${method_args} --loglevel 4`,
            input: input,
        });
    }
    
    function stop() {
        runButton.innerHTML = 'Run';
        worker.terminate();
        worker = undefined;
    }
    
    runButton.addEventListener('click', function() {
        if (!worker)
            start(strategyToText(data.strategy[data.current_strategy_id]), data.strategy[data.current_strategy_id].method || 'check');
        else
            stop();
    });
    
    function loadStrategy(strategy) {
        updateBossImage(bossElement, strategy.boss.paleo_id);
        dinoImage.forEach((image, dino_index) => {
            updateDinoImage(image, strategy.team[dino_index].paleo_id);
        });
        const turnElements = Array.from(abilitiesContainer.querySelectorAll('div.turn'));
        while (turnElements.length > strategy.turn.length) {
            abilitiesContainer.removeChild(turnElements.pop());
        }
        while (turnElements.length < strategy.turn.length) {
            const newTurn = turnElements[0].cloneNode(true);
            abilitiesContainer.appendChild(newTurn);
            initTurn(newTurn, turnElements.length);
            turnElements.push(newTurn);
            abilitiesContainer.appendChild(newTurn);
        }
        turnElements.forEach(updateTurn);
        selectMethod.value = strategy.method || 'check';
    }

    initTurn(firstTurn, 0);
    updateStrategySelect();
    start('', 'version');
    loadStrategy(data.strategy[data.current_strategy_id]);
}
