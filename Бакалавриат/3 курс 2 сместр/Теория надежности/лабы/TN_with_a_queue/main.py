import random
import math

i = 1
j = 10

n = 3
m = 2
lmb = 1.25
tau = 0.333

y = 3.03
ro = 0.413

A = 1.2496
Q = 0.99969
Potk = 0.00031
k = 0.411
Lqueue = 0.00135
Lsys = 0.41235


def wait_queue(queue, delta):
    for i in range(0, len(queue)):
        queue[i][1] += delta


def free_channel(channels):
    for i in range(0, n):
        if channels[i] == 0:
            return i
    return -1


def message_proc(channels, delta):
    for i in range(0, len(channels)):
        if (channels[i] > delta):
            channels[i] -= delta
        else:
            channels[i] = 0


def send_message(messages, channels, queue):
     aqt = 0
     qm = 0
     unpm = 0
     pos = free_channel(channels)
     if pos != -1:
          if len(queue) > 0:
               tmp = queue.pop(0)
               newMessage = tmp[0]

               qm += 1
               aqt += tmp[1]
          else:
               newMessage = messages.pop(0)
          channels[pos] = newMessage
     else:
          if len(queue) < m:
               queue.append([messages.pop(0), 0])
          else:

               unpm += 1
               messages.clear()
     return [aqt, qm, unpm]


channels = []

for i in range(0, n):
    channels.append(0)
queue = []
maxTime = 100000
busyChannels = 0
unProcMessage = 0
totalMessage = 0
avgQueueTime = 0
queueMessage = 0
avgQueueLen = 0
messages = []
t = 0.01
avgTime = 0


for currentTime in range(0, int(maxTime / t)):
    message_proc(channels, t)
    wait_queue(queue, t)
    if (random.random() < 1 - math.exp(-1 * lmb * t)):
        messages.append(0.3 + tau - random.random()/2)
        avgTime += messages[0]
        totalMessage += len(messages)
        take_mes = send_message(messages, channels, queue)
        avgQueueTime += take_mes[0]
        queueMessage += take_mes[1]
        unProcMessage += take_mes[2]
        messages.clear()
    busyChannels += n - channels.count(0)
    avgQueueLen += len(queue)
loadedChannels = busyChannels / (maxTime / t)
averageTime = avgTime / totalMessage

print("Теоретические значения:")
print("Абсолютная пропускная способность: A = {}".format(A))
print("Относительная пропускная способность: Q = {}".format(Q))
print("Вероятность отказа в обработке: P_отк = {}".format(Potk))
print("Среднее число занятых каналов: `k = {}".format(k))
print("Среднее число заявок в очереди: L_оч = {}".format(Lqueue))
print("Среднее число заявок в СМО: L_сист = {}".format(Lsys))

print("\nПрограммные значения:")
print("Сервер работает {} минут, t = {} минуты".format(maxTime, t))
print("Всего получено сообщений: {}".format(totalMessage))
print("Пропущено сообщений: {}".format(unProcMessage))
print("Абсолютная пропускная способность: А = {}".format((totalMessage - unProcMessage) / maxTime))
print("Относительная пропускная способность: Q = {}".format((totalMessage - unProcMessage) / totalMessage))
print("Вероятность отказа при обработке: P_отк = {}".format(unProcMessage / totalMessage))
print("Среднее число занятых каналов при этом составило: k =  {}".format(busyChannels / (maxTime / t)))
print("Среднее число заявок в очереди: L_оч  = {}".format(avgQueueLen / (maxTime / t)))

