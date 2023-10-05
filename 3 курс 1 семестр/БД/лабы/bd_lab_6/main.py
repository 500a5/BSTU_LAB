import psycopg2
from psycopg2 import OperationalError
from tkinter import *
from tkinter import ttk

class BD:  # Класс "БД"
    def __init__(self, db_name, db_user, db_password, db_host, db_port):
        try:
            self.connection = psycopg2.connect(
                database=db_name,
                user=db_user,
                password=db_password,
                host=db_host,
                port=db_port,
            )
            self.cursor = self.connection.cursor()
        except OperationalError as e:
            print(f"The error '{e}' occurred")

    # Исполнение запроса
    def execute(self, query):
        try:
            self.cursor.execute(query)
            self.connection.commit()
            return True
        except OperationalError as e:
            print(f"The error '{e}' occurred")
            return False
    # Выборка из БД
    def select(self, query):
        try:
            self.cursor.execute(query)
            res = self.cursor.fetchall()
            return res
        except OperationalError as e:
            print(f"The error '{e}' occurred")
            return None
    # Вывод таблицы БД на экран

    def print_table(self, table_name):
        self.cursor.execute(f"SELECT * FROM {table_name}")
        header = [i[0] for i in self.cursor.description]
        body = self.cursor.fetchall()
        max_len = max([len(x) for x in header])
        for i in body:
            for j in i:
                if len(str(j)) > max_len:
                    max_len = len(str(j))
        max_len += 2
        for i in header:
            print("|", ("{:^" + str(max_len) + "s}").format(i), "|", end="")
        print("\n| ", "-" * (max_len + 2) * len(header), " |")
        for i in body:
            for j in i:
                print("|", ("{:^" + str(max_len) + "s}").format(str(j)), "|", end="")
            print()

    def str_table(self, table_name):
        res = []
        self.cursor.execute(f"SELECT * FROM {table_name}");
        header = [i[0] for i in self.cursor.description]  # Получим имена столбцов таблицы
        body = self.cursor.fetchall()  # Получим список строк таблицы
        max_len = 0  # Найдем максимальную длину поля таблицы в строковом представлении
        for i in header:
            if len(i) > max_len:
                max_len = len(i)
        for i in body:
            for j in i:
                if len(str(j)) > max_len:
                    max_len = len(str(j))
        max_len += 2
        bufStr = ""
        for i in header:  # Выведем таблицу
            bufStr += "|" + ("{:^" + str(max_len) + "s}").format(i) + "|"
        res.append(bufStr)
        res.append("|  " + "-" * (max_len + 2) * len(header) + "  |")
        for i in body:
            bufStr = ""
            for j in i:
                bufStr += "|" + ("{:^" + str(max_len) + "s}").format(str(j)) + "|"
            res.append(bufStr)
        return '\n'.join(res)

# курьер
def insert_courier_contact_details():
    queryInsertcourier = f"""INSERT INTO courier_contact_details (id, fio, phone, email) 
                        VALUES ({text_courier_contact_details_id.get()}, '{text_courier_contact_details_fio.get()}', '{text_courier_contact_details_phone.get()}', '{text_courier_contact_details_email.get()}')"""
    bd.execute(queryInsertcourier)

def output_courier_contact_details():
    textOutputCourier.delete(1.0, END)
    textOutputCourier.insert(1.0, bd.str_table("courier_contact_details"))

def insert_courier():
    queryInsertcourier = f"""INSERT INTO courier (id, id_transport, location, id_delivery_order, id_contact_details) 
                        VALUES ({text_courier_id.get()}, {text_courier_id_transport.get()}, '{text_courier_location.get()}', {text_courier_id_delivery_order.get()}, {text_courier_id_contact_details.get()})"""
    bd.execute(queryInsertcourier)

def output_courier():
    textOutputCourier.delete(1.0, END)
    textOutputCourier.insert(1.0, bd.str_table("courier"))

def insert_type_transport():
    queryInsertcourier = f"""INSERT INTO type_transport (id, type) 
                       VALUES ({text_type_transport_id.get()},'{text_type_transport_type.get()}')"""
    bd.execute(queryInsertcourier)

def output_type_transport():
    textOutputTransport.delete(1.0, END)
    textOutputTransport.insert(1.0, bd.str_table("type_transport"))

def insert_size_transport():
    queryInsertTransport = f"""INSERT INTO type_size_transport (id, size, id_type) 
                       VALUES ({text_size_transport_id.get()},{text_size_transport_size.get()}, {text_size_transport_type.get()})"""
    bd.execute(queryInsertTransport)

def output_size_transport():
    textOutputTransport.delete(1.0, END)
    textOutputTransport.insert(1.0, bd.str_table("type_size_transport"))

def insert_model_transport():
    queryInsertTransport = f"""INSERT INTO model_transport (id, model) 
                       VALUES ({text_model_transport_id.get()},'{text_model_transport_model.get()}')"""
    bd.execute(queryInsertTransport)

def output_model_transport():
    textOutputTransport.delete(1.0, END)
    textOutputTransport.insert(1.0, bd.str_table("model_transport"))

def insert_transport():
    queryInsertTransport = f"""INSERT INTO transport (id, id_type_size, model) 
                       VALUES ({text_transport_id.get()},{text_transport_type_size.get()},{text_transport_model.get()})"""
    bd.execute(queryInsertTransport)

def output_transport():
    textOutputTransport.delete(1.0, END)
    textOutputTransport.insert(1.0, bd.str_table("transport"))

def insert_transport_company_contact():
    queryInsertTransportCompany = f"""INSERT INTO transport_company_contact_details (id, name, description, email, phone) 
                       VALUES ({text_transport_company_contact_id.get()},  '{text_transport_company_contact_name.get()}','{text_transport_company_contact_dscription.get()}','{text_transport_company_contact_email.get()}','{text_transport_company_contact_phone.get()}')"""
    bd.execute(queryInsertTransportCompany)

def output_transport_company_contact():
    textOutputTransportCompany.delete(1.0, END)
    textOutputTransportCompany.insert(1.0, bd.str_table("transport_company_contact_details"))

def insert_transport_company():
    queryInsertTransportCompany = f"""INSERT INTO transport_company (id, id_courier, id_delivery_order, id_adress, id_contact_details) 
                       VALUES ({text_transport_company_id.get()},{text_transport_company_id_courier.get()},{text_transport_company_id_order.get()},{text_transport_company_id_adress.get()},{text_transport_company_id_contact_details.get()})"""
    bd.execute(queryInsertTransportCompany)

def output_transport_company():
    textOutputTransportCompany.delete(1.0, END)
    textOutputTransportCompany.insert(1.0, bd.str_table("transport_company"))

def insert_delivery_order_type():
    queryInsertOutputDeliveryOrder = f"""INSERT INTO delivery_type (id, type) 
                       VALUES ({text_delivery_order_type_id.get()},'{text_delivery_order_type_type.get()}')"""
    bd.execute(queryInsertOutputDeliveryOrder)

def output_delivery_order_type():
    textOutputDeliveryOrder.delete(1.0, END)
    textOutputDeliveryOrder.insert(1.0, bd.str_table("type_delivery"))

def insert_delivery_order():
    queryInsertOutputDeliveryOrder = f"""INSERT INTO delivery_order(id, id_product, price, start_date, end_date, type_delivery) 
                       VALUES ({text_delivery_order_id.get()},{text_delivery_order_id_product.get()},{text_delivery_order_price.get()},'{text_delivery_order_start_date.get()}', ,'{text_delivery_order_end_date.get()}', ,{text_delivery_order_type_delivery.get()})"""
    bd.execute(queryInsertOutputDeliveryOrder)

def output_delivery_order():
    textOutputDeliveryOrder.delete(1.0, END)
    textOutputDeliveryOrder.insert(1.0, bd.str_table("delivery_order"))

def insert_provider_contact():
    queryInsertProvider = f"""INSERT INTO provider_contact_details (id, name, description, email, phone) 
                       VALUES ({text_provider_contact_details_id.get()},'{text_provider_contact_details_name.get()}','{text_provider_contact_details_dscription.get()}','{text_provider_contact_details_email.get()}','{text_provider_contact_details_phone.get()}')"""
    bd.execute(queryInsertProvider)

def output_provider_contact():
    textOutputProvider.delete(1.0, END)
    textOutputProvider.insert(1.0, bd.str_table("provider_contact_details"))

def insert_provider():
    queryInsertProvider = f"""INSERT INTO provider (id, id_product, id_address, id_contact_details) 
                       VALUES ({text_provider_id.get()},{text_provider_id_product.get()},{text_provider_id_adress.get()},{text_provider_id_contact_details.get()})"""
    bd.execute(queryInsertProvider)

def output_provider():
    textOutputProvider.delete(1.0, END)
    textOutputProvider.insert(1.0, bd.str_table("provider"))

def insert_name_product():
    queryInsertProduct = f"""INSERT INTO name_product (id, name) 
                       VALUES ({text_name_product_id.get()},'{text_name_product_name.get()}')"""
    bd.execute(queryInsertProduct)

def output_name_product():
    textOutputProduct.delete(1.0, END)
    textOutputProduct.insert(1.0, bd.str_table("name_product"))

def insert_product():
    queryInsertProduct = f"""INSERT INTO product (id, size, weight, id_name, address) 
                       VALUES ({text_product_id.get()},{text_product_size.get()},{text_product_weight.get()},{text_product_id_name.get()},,{text_product_id_adress.get()})"""
    bd.execute(queryInsertProduct)

def output_product():
    textOutputProduct.delete(1.0, END)
    textOutputProduct.insert(1.0, bd.str_table("product"))

def insert_consumer_contact():
    queryInsertConsumer = f"""INSERT INTO consumer_contact_details (id, name, description, email, phone) 
                       VALUES ({text_consumer_contact_id.get()},'{text_consumer_contact_name.get()}','{text_consumer_contact_dscription.get()}','{text_consumer_contact_email.get()}','{text_consumer_contact_phone.get()}')"""
    bd.execute(queryInsertConsumer)

def output_consumer_contact():
    textOutputСonsumer.delete(1.0, END)
    textOutputСonsumer.insert(1.0, bd.str_table("consumer_contact_details"))

def insert_consumer():
    queryInsertConsumer = f"""INSERT INTO consumer (id, id_delivery_order, id_address, contact_details) 
                       VALUES ({text_consumer_id.get()},{text_consumer_id_order.get()},{text_consumer_id_adress.get()},{text_consumer_id_contact_details.get()})"""
    bd.execute(queryInsertConsumer)

def output_consumer():
    textOutputСonsumer.delete(1.0, END)
    textOutputСonsumer.insert(1.0, bd.str_table("consumer"))

def insert_stoc():
    queryInsertStoc = f"""INSERT INTO stoc (id, id_product, address_stoc) 
                       VALUES ({text_stoc_id.get()},{text_size_transport_size.get()},{text_stoc_id_addres.get()})"""
    bd.execute(queryInsertStoc)

def output_stoc():
    textOutputStoc.delete(1.0, END)
    textOutputStoc.insert(1.0, bd.str_table("stoc"))

def insert_addres_county():
    queryInsertAddres = f"""INSERT INTO country (id, county) 
                       VALUES ({text_addres_country_id.get()},{text_addres_country_name.get()})"""
    bd.execute(queryInsertAddres)

def output_addres_county():
    textOutputAddres.delete(1.0, END)
    textOutputAddres.insert(1.0, bd.str_table("country"))

def insert_addres_sity():
    queryInsertAddres = f"""INSERT INTO city (id, city) 
                       VALUES ({text_addres_city_id.get()},{text_addres_city_name.get()})"""
    bd.execute(queryInsertAddres)

def output_addres_sity():
    textOutputAddres.delete(1.0, END)
    textOutputAddres.insert(1.0, bd.str_table("city"))

def insert_addres_street():
    queryInsertAddres = f"""INSERT INTO street (id, street) 
                       VALUES ({text_addres_street_id.get()},{text_addres_street_name.get()})"""
    bd.execute(queryInsertAddres)

def output_addres_street():
    textOutputAddres.delete(1.0, END)
    textOutputAddres.insert(1.0, bd.str_table("street"))

def insert_addres_bilding():
    queryInsertAddres = f"""INSERT INTO street (id, bilding) 
                       VALUES ({text_addres_bilding_id.get()},{text_addres_bilding_name.get()})"""
    bd.execute(queryInsertAddres)

def output_addres_bilding():
    textOutputAddres.delete(1.0, END)
    textOutputAddres.insert(1.0, bd.str_table("bilding"))

def insert_addres():
    queryInsertAddres = f"""INSERT INTO address (id, country, city, street, bilding) 
                       VALUES ({text_addres_id.get()},{text_addres_county.get()},{text_addres_city.get()},{text_addres_street.get()},,{text_addres_bilding.get()})"""
    bd.execute(queryInsertAddres)

def output_addres():
    textOutputAddres.delete(1.0, END)
    textOutputAddres.insert(1.0, bd.str_table("address"))
if __name__ == '__main__':
    bd = BD("postgres", "postgres", "123456789", "localhost", "5432")


    window = Tk()
    window.title('База данных транспортной компании')
    window.geometry('1200x800')
    tables = ttk.Notebook(window)





    # курьер
    frame_courier = ttk.Frame(tables)
    tables.add(frame_courier, text='Курьер')
    tables.pack(expand=2, fill='both')

    lbl = Label(frame_courier, text="Контактные данные куьера")
    lbl.grid(row=0,column=1)

    label_courier_contact_details_id = Label(frame_courier, text='id:')
    label_courier_contact_details_id.grid(row=1, column=0)
    text_courier_contact_details_id = Entry(frame_courier, width=40)
    text_courier_contact_details_id.grid(row=1, column=1)

    label_courier_id = Label(frame_courier, text='ФИО:')
    label_courier_id.grid(row=2, column=0)
    text_courier_contact_details_fio = Entry(frame_courier, width=40)
    text_courier_contact_details_fio.grid(row=2, column=1)

    label_courier_contact_details_phone = Label(frame_courier, text='телефон:')
    label_courier_contact_details_phone.grid(row=3, column=0)
    text_courier_contact_details_phone = Entry(frame_courier, width=40)
    text_courier_contact_details_phone.grid(row=3, column=1)

    label_courier_contact_details_email = Label(frame_courier, text='почта:')
    label_courier_contact_details_email.grid(row=4, column=0)
    text_courier_contact_details_email = Entry(frame_courier, width=40)
    text_courier_contact_details_email.grid(row=4, column=1)

    btn = Button(frame_courier, text='Добавить', command=insert_courier_contact_details)
    btn.grid(row=5, column=0)

    btnOutput = Button(frame_courier, text='Вывести таблицу', command=output_courier_contact_details)
    btnOutput.grid(row=5, column=1)

    lbl = Label(frame_courier, text="Курьер")
    lbl.grid(row=6, column=1)

    label_courier_id = Label(frame_courier, text='id:')
    label_courier_id.grid(row=7, column=0)
    text_courier_id = Entry(frame_courier, width=40)
    text_courier_id.grid(row=7, column=1)

    label_courier_id_transport = Label(frame_courier, text='id транспорта:')
    label_courier_id_transport.grid(row=8, column=0)
    text_courier_id_transport = Entry(frame_courier, width=40)
    text_courier_id_transport.grid(row=8, column=1)

    label_courier_location = Label(frame_courier, text='местоположение:')
    label_courier_location.grid(row=9, column=0)
    text_courier_location = Entry(frame_courier, width=40)
    text_courier_location.grid(row=9, column=1)


    label_courier_id_delivery_order = Label(frame_courier, text='id заказа:')
    label_courier_id_delivery_order.grid(row=10, column=0)
    text_courier_id_delivery_order = Entry(frame_courier, width=40)
    text_courier_id_delivery_order.grid(row=10, column=1)


    label_courier_id_contact_details = Label(frame_courier, text='id контактных данных:')
    label_courier_id_contact_details.grid(row=11, column=0)
    text_courier_id_contact_details = Entry(frame_courier, width=40)
    text_courier_id_contact_details.grid(row=11, column=1)

    btn = Button(frame_courier, text='Добавить', command=insert_courier)
    btn.grid(row=12, column=0)

    btnOutput = Button(frame_courier, text='Вывести таблицу', command=output_courier)
    btnOutput.grid(row=12, column=1)

    textOutputCourier = Text(frame_courier, width=200, height=20, font='Consolas 10')
    textOutputCourier.place(x=10, y=300)

    # транспорт
    frame_transport = ttk.Frame(tables)
    tables.add(frame_transport, text='Транспорт')
    tables.pack(expand=2, fill='both')

    lbl = Label(frame_transport, text="Тип транспорта")
    lbl.grid(row=0, column=1)

    label_type_transport_id = Label(frame_transport, text='id:')
    label_type_transport_id.grid(row=1, column=0)
    text_type_transport_id = Entry(frame_transport, width=40)
    text_type_transport_id.grid(row=1, column=1)

    label_type_transport_type = Label(frame_transport, text='тип:')
    label_type_transport_type.grid(row=2, column=0)
    text_type_transport_type = Entry(frame_transport, width=40)
    text_type_transport_type.grid(row=2, column=1)

    btn = Button(frame_transport, text='Добавить', command=insert_type_transport)
    btn.grid(row=3, column=0)

    btnOutput = Button(frame_transport, text='Вывести таблицу', command=output_type_transport)
    btnOutput.grid(row=3, column=1)

    lbl = Label(frame_transport, text="Размер транспорта")
    lbl.grid(row=0, column=3)

    label_size_transport_id = Label(frame_transport, text='id:')
    label_size_transport_id.grid(row=1, column=2)
    text_size_transport_id = Entry(frame_transport, width=40)
    text_size_transport_id.grid(row=1, column=3)

    label_size_transport_size = Label(frame_transport, text='размер:')
    label_size_transport_size.grid(row=2, column=2)
    text_size_transport_size = Entry(frame_transport, width=40)
    text_size_transport_size.grid(row=2, column=3)

    label_size_transport_type = Label(frame_transport, text='тип транспорта:')
    label_size_transport_type.grid(row=3, column=2)
    text_size_transport_type = Entry(frame_transport, width=40)
    text_size_transport_type.grid(row=3, column=3)

    btn = Button(frame_transport, text='Добавить', command=insert_size_transport)
    btn.grid(row=4, column=2)

    btnOutput = Button(frame_transport, text='Вывести таблицу', command=output_size_transport)
    btnOutput.grid(row=4, column=3)

    lbl = Label(frame_transport, text="Модель транспорта")
    lbl.grid(row=0, column=5)

    label_model_transport_id = Label(frame_transport, text='id:')
    label_model_transport_id.grid(row=1, column=4)
    text_model_transport_id = Entry(frame_transport, width=40)
    text_model_transport_id.grid(row=1, column=5)

    label_model_transport_model = Label(frame_transport, text='модель:')
    label_model_transport_model.grid(row=2, column=4)
    text_model_transport_model = Entry(frame_transport, width=40)
    text_model_transport_model.grid(row=2, column=5)

    btn = Button(frame_transport, text='Добавить', command=insert_model_transport)
    btn.grid(row=3, column=4)

    btnOutput = Button(frame_transport, text='Вывести таблицу', command=output_model_transport)
    btnOutput.grid(row=3, column=5)

    lbl = Label(frame_transport, text="Транспорт")
    lbl.grid(row=5, column=1)

    label_transport_id = Label(frame_transport, text='id:')
    label_transport_id.grid(row=6, column=0)
    text_transport_id = Entry(frame_transport, width=40)
    text_transport_id.grid(row=6, column=1)

    label_transport_type_size = Label(frame_transport, text='id типа и размера:')
    label_transport_type_size.grid(row=7, column=0)
    text_transport_type_size = Entry(frame_transport, width=40)
    text_transport_type_size.grid(row=7, column=1)

    label_transport_model = Label(frame_transport, text='модель:')
    label_transport_model.grid(row=8, column=0)
    text_transport_model = Entry(frame_transport, width=40)
    text_transport_model.grid(row=8, column=1)

    btn = Button(frame_transport, text='Добавить', command=insert_transport)
    btn.grid(row=9, column=0)

    btnOutput = Button(frame_transport, text='Вывести таблицу', command=output_transport)
    btnOutput.grid(row=9, column=1)

    textOutputTransport = Text(frame_transport, width=200, height=20, font='Consolas 10')
    textOutputTransport.place(x=10, y=300)

    # транспортная компания
    frame_transport_company = ttk.Frame(tables)
    tables.add(frame_transport_company, text='Транспортная компания')
    tables.pack(expand=2, fill='both')

    lbl = Label(frame_transport_company, text="контакты компании")
    lbl.grid(row=0, column=1)

    label_transport_company_contact_id = Label(frame_transport_company, text='id:')
    label_transport_company_contact_id.grid(row=1, column=0)
    text_transport_company_contact_id = Entry(frame_transport_company, width=40)
    text_transport_company_contact_id.grid(row=1, column=1)

    label_transport_company_contact_name = Label(frame_transport_company, text='название:')
    label_transport_company_contact_name.grid(row=2, column=0)
    text_transport_company_contact_name = Entry(frame_transport_company, width=40)
    text_transport_company_contact_name.grid(row=2, column=1)

    label_transport_company_contact_dscription = Label(frame_transport_company, text='описание:')
    label_transport_company_contact_dscription.grid(row=3, column=0)
    text_transport_company_contact_dscription = Entry(frame_transport_company, width=40)
    text_transport_company_contact_dscription.grid(row=3, column=1)

    label_transport_company_contact_email = Label(frame_transport_company, text='email:')
    label_transport_company_contact_email.grid(row=4, column=0)
    text_transport_company_contact_email = Entry(frame_transport_company, width=40)
    text_transport_company_contact_email.grid(row=4, column=1)

    label_transport_company_contact_phone = Label(frame_transport_company, text='телефон:')
    label_transport_company_contact_phone.grid(row=5, column=0)
    text_transport_company_contact_phone = Entry(frame_transport_company, width=40)
    text_transport_company_contact_phone.grid(row=5, column=1)

    btn = Button(frame_transport_company, text='Добавить', command=insert_transport_company_contact)
    btn.grid(row=6, column=0)

    btnOutput = Button(frame_transport_company, text='Вывести таблицу', command=output_transport_company_contact)
    btnOutput.grid(row=6, column=1)

    lbl = Label(frame_transport_company, text="транспортная компания")
    lbl.grid(row=0, column=3)

    label_transport_company_id = Label(frame_transport_company, text='id:')
    label_transport_company_id.grid(row=1, column=2)
    text_transport_company_id = Entry(frame_transport_company, width=40)
    text_transport_company_id.grid(row=1, column=3)

    label_transport_company_id_courier = Label(frame_transport_company, text='id курьера:')
    label_transport_company_id_courier.grid(row=2, column=2)
    text_transport_company_id_courier = Entry(frame_transport_company, width=40)
    text_transport_company_id_courier.grid(row=2, column=3)

    label_transport_company_id_order = Label(frame_transport_company, text='id заказа:')
    label_transport_company_id_order.grid(row=3, column=2)
    text_transport_company_id_order = Entry(frame_transport_company, width=40)
    text_transport_company_id_order.grid(row=3, column=3)

    label_transport_company_id_adress = Label(frame_transport_company, text='id адреса:')
    label_transport_company_id_adress.grid(row=4, column=2)
    text_transport_company_id_adress = Entry(frame_transport_company, width=40)
    text_transport_company_id_adress.grid(row=4, column=3)

    label_transport_company_id_contact_details = Label(frame_transport_company, text='id контактных данных:')
    label_transport_company_id_contact_details.grid(row=5, column=2)
    text_transport_company_id_contact_details = Entry(frame_transport_company, width=40)
    text_transport_company_id_contact_details.grid(row=5, column=3)

    btn = Button(frame_transport_company, text='Добавить', command=insert_transport_company)
    btn.grid(row=6, column=2)

    btnOutput = Button(frame_transport_company, text='Вывести таблицу', command=output_transport_company)
    btnOutput.grid(row=6, column=3)


    textOutputTransportCompany = Text(frame_transport_company, width=200, height=20, font='Consolas 10')
    textOutputTransportCompany.place(x=10, y=300)

    # заказ доставка
    frame_delivery_order = ttk.Frame(tables)
    tables.add(frame_delivery_order, text='Заказ доставки')
    tables.pack(expand=2, fill='both')

    lbl = Label(frame_delivery_order, text="тип доставки")
    lbl.grid(row=0, column=1)

    label_delivery_order_type_id = Label(frame_delivery_order, text='id:')
    label_delivery_order_type_id.grid(row=1, column=0)
    text_delivery_order_type_id = Entry(frame_delivery_order, width=40)
    text_delivery_order_type_id.grid(row=1, column=1)

    label_delivery_order_type_type = Label(frame_delivery_order, text='тип:')
    label_delivery_order_type_type.grid(row=2, column=0)
    text_delivery_order_type_type = Entry(frame_delivery_order, width=40)
    text_delivery_order_type_type.grid(row=2, column=1)

    btn = Button(frame_delivery_order, text='Добавить', command=insert_delivery_order_type)
    btn.grid(row=3, column=0)

    btnOutput = Button(frame_delivery_order, text='Вывести таблицу', command=output_delivery_order_type)
    btnOutput.grid(row=3, column=1)

    lbl = Label(frame_delivery_order, text="заказ доставки")
    lbl.grid(row=0, column=3)

    label_delivery_order_id = Label(frame_delivery_order, text='id:')
    label_delivery_order_id.grid(row=1, column=2)
    text_delivery_order_id = Entry(frame_delivery_order, width=40)
    text_delivery_order_id.grid(row=1, column=3)

    label_delivery_order_id_product = Label(frame_delivery_order, text='id товара:')
    label_delivery_order_id_product.grid(row=2, column=2)
    text_delivery_order_id_product = Entry(frame_delivery_order, width=40)
    text_delivery_order_id_product.grid(row=2, column=3)

    label_delivery_order_price = Label(frame_delivery_order, text='цена:')
    label_delivery_order_price.grid(row=3, column=2)
    text_delivery_order_price = Entry(frame_delivery_order, width=40)
    text_delivery_order_price.grid(row=3, column=3)

    label_delivery_order_start_date = Label(frame_delivery_order, text='дата поступления:')
    label_delivery_order_start_date.grid(row=4, column=2)
    text_delivery_order_start_date = Entry(frame_delivery_order, width=40)
    text_delivery_order_start_date.grid(row=4, column=3)

    label_delivery_order_end_date = Label(frame_delivery_order, text='дата завершения:')
    label_delivery_order_end_date.grid(row=5, column=2)
    text_delivery_order_end_date = Entry(frame_delivery_order, width=40)
    text_delivery_order_end_date.grid(row=5, column=3)

    label_delivery_order_type_delivery = Label(frame_delivery_order, text='id типа доставки:')
    label_delivery_order_type_delivery.grid(row=6, column=2)
    text_delivery_order_type_delivery = Entry(frame_delivery_order, width=40)
    text_delivery_order_type_delivery.grid(row=6, column=3)

    btn = Button(frame_delivery_order, text='Добавить', command=insert_delivery_order)
    btn.grid(row=7, column=2)

    btnOutput = Button(frame_delivery_order, text='Вывести таблицу', command=output_delivery_order)
    btnOutput.grid(row=7, column=3)

    textOutputDeliveryOrder = Text(frame_delivery_order, width=200, height=20, font='Consolas 10')
    textOutputDeliveryOrder.place(x=10, y=300)

    # поставщик
    frame_provider_contact_details = ttk.Frame(tables)
    tables.add(frame_provider_contact_details, text='Поставщик')
    tables.pack(expand=2, fill='both')

    lbl = Label(frame_provider_contact_details, text="контакты поставщика")
    lbl.grid(row=0, column=1)

    label_provider_contact_details_id = Label(frame_provider_contact_details, text='id:')
    label_provider_contact_details_id.grid(row=1, column=0)
    text_provider_contact_details_id = Entry(frame_provider_contact_details, width=40)
    text_provider_contact_details_id.grid(row=1, column=1)

    label_provider_contact_details_name = Label(frame_provider_contact_details, text='название:')
    label_provider_contact_details_name.grid(row=2, column=0)
    text_provider_contact_details_name = Entry(frame_provider_contact_details, width=40)
    text_provider_contact_details_name.grid(row=2, column=1)

    label_provider_contact_details_dscription = Label(frame_provider_contact_details, text='описание:')
    label_provider_contact_details_dscription.grid(row=3, column=0)
    text_provider_contact_details_dscription = Entry(frame_provider_contact_details, width=40)
    text_provider_contact_details_dscription.grid(row=3, column=1)

    label_provider_contact_details_email = Label(frame_provider_contact_details, text='email:')
    label_provider_contact_details_email.grid(row=4, column=0)
    text_provider_contact_details_email = Entry(frame_provider_contact_details, width=40)
    text_provider_contact_details_email.grid(row=4, column=1)

    label_provider_contact_details_phone = Label(frame_provider_contact_details, text='телефон:')
    label_provider_contact_details_phone.grid(row=5, column=0)
    text_provider_contact_details_phone = Entry(frame_provider_contact_details, width=40)
    text_provider_contact_details_phone.grid(row=5, column=1)

    btn = Button(frame_provider_contact_details, text='Добавить', command=insert_provider_contact)
    btn.grid(row=6, column=0)

    btnOutput = Button(frame_provider_contact_details, text='Вывести таблицу', command=output_provider_contact)
    btnOutput.grid(row=6, column=1)

    lbl = Label(frame_provider_contact_details, text="поставщик")
    lbl.grid(row=0, column=3)

    label_provider_id = Label(frame_provider_contact_details, text='id:')
    label_provider_id.grid(row=1, column=2)
    text_provider_id = Entry(frame_provider_contact_details, width=40)
    text_provider_id.grid(row=1, column=3)

    label_provider_id_product = Label(frame_provider_contact_details, text='id продукта:')
    label_provider_id_product.grid(row=2, column=2)
    text_provider_id_product = Entry(frame_provider_contact_details, width=40)
    text_provider_id_product.grid(row=2, column=3)

    label_provider_id_adress = Label(frame_provider_contact_details, text='id адреса:')
    label_provider_id_adress.grid(row=3, column=2)
    text_provider_id_adress = Entry(frame_provider_contact_details, width=40)
    text_provider_id_adress.grid(row=3, column=3)

    label_provider_id_contact_details = Label(frame_provider_contact_details, text='id контактных данных:')
    label_provider_id_contact_details.grid(row=4, column=2)
    text_provider_id_contact_details = Entry(frame_provider_contact_details, width=40)
    text_provider_id_contact_details.grid(row=4, column=3)

    btn = Button(frame_provider_contact_details, text='Добавить', command=insert_provider)
    btn.grid(row=5, column=2)

    btnOutput = Button(frame_provider_contact_details, text='Вывести таблицу', command=output_provider)
    btnOutput.grid(row=5, column=3)

    textOutputProvider = Text(frame_provider_contact_details, width=200, height=20, font='Consolas 10')
    textOutputProvider.place(x=10, y=300)

    # товар
    frame_product = ttk.Frame(tables)
    tables.add(frame_product, text='Товар')
    tables.pack(expand=2, fill='both')

    lbl = Label(frame_product, text="наименование товара")
    lbl.grid(row=0, column=1)

    label_name_product_id = Label(frame_product, text='id:')
    label_name_product_id.grid(row=1, column=0)
    text_name_product_id = Entry(frame_product, width=40)
    text_name_product_id.grid(row=1, column=1)

    label_name_product_name = Label(frame_product, text='название:')
    label_name_product_name.grid(row=2, column=0)
    text_name_product_name = Entry(frame_product, width=40)
    text_name_product_name.grid(row=2, column=1)

    btn = Button(frame_product, text='Добавить', command=insert_name_product)
    btn.grid(row=3, column=0)

    btnOutput = Button(frame_product, text='Вывести таблицу', command=output_name_product)
    btnOutput.grid(row=3, column=1)

    lbl = Label(frame_product, text="товар")
    lbl.grid(row=0, column=3)

    label_product_id = Label(frame_product, text='id:')
    label_product_id.grid(row=1, column=2)
    text_product_id = Entry(frame_product, width=40)
    text_product_id.grid(row=1, column=3)

    label_product_size = Label(frame_product, text='размер:')
    label_product_size.grid(row=2, column=2)
    text_product_size = Entry(frame_product, width=40)
    text_product_size.grid(row=2, column=3)

    label_product_weight = Label(frame_product, text='вес:')
    label_product_weight.grid(row=3, column=2)
    text_product_weight = Entry(frame_product, width=40)
    text_product_weight.grid(row=3, column=3)

    label_product_id_name = Label(frame_product, text='id наименования:')
    label_product_id_name.grid(row=4, column=2)
    text_product_id_name = Entry(frame_product, width=40)
    text_product_id_name.grid(row=4, column=3)

    label_product_id_adress = Label(frame_product, text='адрес где товар:')
    label_product_id_adress.grid(row=5, column=2)
    text_product_id_adress = Entry(frame_product, width=40)
    text_product_id_adress.grid(row=5, column=3)

    btn = Button(frame_product, text='Добавить', command=insert_product)
    btn.grid(row=6, column=2)

    btnOutput = Button(frame_product, text='Вывести таблицу', command=output_product)
    btnOutput.grid(row=6, column=3)

    textOutputProduct = Text(frame_product, width=200, height=20, font='Consolas 10')
    textOutputProduct.place(x=10, y=300)

    # потребитель
    frame_consumer = ttk.Frame(tables)
    tables.add(frame_consumer, text='Потребитель')
    tables.pack(expand=2, fill='both')

    lbl = Label(frame_consumer, text="контакты потребителя")
    lbl.grid(row=0, column=1)

    label_consumer_contact_id = Label(frame_consumer, text='id:')
    label_consumer_contact_id.grid(row=1, column=0)
    text_consumer_contact_id = Entry(frame_consumer, width=40)
    text_consumer_contact_id.grid(row=1, column=1)

    label_consumer_contact_name = Label(frame_consumer, text='название:')
    label_consumer_contact_name.grid(row=2, column=0)
    text_consumer_contact_name = Entry(frame_consumer, width=40)
    text_consumer_contact_name.grid(row=2, column=1)

    label_consumer_contact_dscription = Label(frame_consumer, text='описание:')
    label_consumer_contact_dscription.grid(row=3, column=0)
    text_consumer_contact_dscription = Entry(frame_consumer, width=40)
    text_consumer_contact_dscription.grid(row=3, column=1)

    label_consumer_contact_email = Label(frame_consumer, text='email:')
    label_consumer_contact_email.grid(row=4, column=0)
    text_consumer_contact_email = Entry(frame_consumer, width=40)
    text_consumer_contact_email.grid(row=4, column=1)

    label_consumer_contact_phone = Label(frame_consumer, text='телефон:')
    label_consumer_contact_phone.grid(row=5, column=0)
    text_consumer_contact_phone = Entry(frame_consumer, width=40)
    text_consumer_contact_phone.grid(row=5, column=1)

    btn = Button(frame_consumer, text='Добавить', command=insert_consumer_contact)
    btn.grid(row=6, column=0)

    btnOutput = Button(frame_consumer, text='Вывести таблицу', command=output_consumer_contact)
    btnOutput.grid(row=6, column=1)

    lbl = Label(frame_consumer, text="потребитель")
    lbl.grid(row=0, column=3)

    label_consumer_id = Label(frame_consumer, text='id:')
    label_consumer_id.grid(row=1, column=2)
    text_consumer_id = Entry(frame_consumer, width=40)
    text_consumer_id.grid(row=1, column=3)

    label_consumer_id_order = Label(frame_consumer, text='id заказа:')
    label_consumer_id_order.grid(row=2, column=2)
    text_consumer_id_order = Entry(frame_consumer, width=40)
    text_consumer_id_order.grid(row=2, column=3)

    label_consumer_id_adress = Label(frame_consumer, text='id адреса:')
    label_consumer_id_adress.grid(row=3, column=2)
    text_consumer_id_adress = Entry(frame_consumer, width=40)
    text_consumer_id_adress.grid(row=3, column=3)

    label_consumer_id_contact_details = Label(frame_consumer, text='id контактных данных:')
    label_consumer_id_contact_details.grid(row=4, column=2)
    text_consumer_id_contact_details = Entry(frame_consumer, width=40)
    text_consumer_id_contact_details.grid(row=4, column=3)

    btn = Button(frame_consumer, text='Добавить', command=insert_transport_company)
    btn.grid(row=5, column=2)

    btnOutput = Button(frame_consumer, text='Вывести таблицу', command=output_consumer)
    btnOutput.grid(row=5, column=3)

    textOutputСonsumer = Text(frame_consumer, width=200, height=20, font='Consolas 10')
    textOutputСonsumer.place(x=10, y=200)

    # склад
    frame_stoc = ttk.Frame(tables)
    tables.add(frame_stoc, text='Склад')
    tables.pack(expand=2, fill='both')

    lbl = Label(frame_stoc, text="склад")
    lbl.grid(row=0, column=1)

    label_stoc_id = Label(frame_stoc, text='id:')
    label_stoc_id.grid(row=1, column=0)
    text_stoc_id = Entry(frame_stoc, width=40)
    text_stoc_id.grid(row=1, column=1)

    label_stoc_id_product = Label(frame_stoc, text='id продукта:')
    label_stoc_id_product.grid(row=2, column=0)
    text_stoc_id_product = Entry(frame_stoc, width=40)
    text_stoc_id_product.grid(row=2, column=1)

    label_stoc_id_addres = Label(frame_stoc, text='id адреса:')
    label_stoc_id_addres.grid(row=3, column=0)
    text_stoc_id_addres = Entry(frame_stoc, width=40)
    text_stoc_id_addres.grid(row=3, column=1)

    btn = Button(frame_stoc, text='Добавить', command=insert_stoc)
    btn.grid(row=4, column=0)

    btnOutput = Button(frame_stoc, text='Вывести таблицу', command=output_stoc)
    btnOutput.grid(row=4, column=1)

    textOutputStoc = Text(frame_stoc, width=200, height=20, font='Consolas 10')
    textOutputStoc.place(x=10, y=200)

    # адресс
    frame_addres = ttk.Frame(tables)
    tables.add(frame_addres, text='Адрес')
    tables.pack(expand=2, fill='both')

    lbl = Label(frame_addres, text="страна")
    lbl.grid(row=0, column=1)

    label_addres_country_id = Label(frame_addres, text='id:')
    label_addres_country_id.grid(row=1, column=0)
    text_addres_country_id = Entry(frame_addres, width=40)
    text_addres_country_id.grid(row=1, column=1)

    label_addres_country_name = Label(frame_addres, text='название:')
    label_addres_country_name.grid(row=2, column=0)
    text_addres_country_name = Entry(frame_addres, width=40)
    text_addres_country_name.grid(row=2, column=1)

    btn = Button(frame_addres, text='Добавить', command=insert_addres_county)
    btn.grid(row=3, column=0)

    btnOutput = Button(frame_addres, text='Вывести таблицу', command=output_addres_county)
    btnOutput.grid(row=3, column=1)

    lbl = Label(frame_addres, text="город")
    lbl.grid(row=0, column=3)

    label_addres_city_id = Label(frame_addres, text='id:')
    label_addres_city_id.grid(row=1, column=2)
    text_addres_city_id = Entry(frame_addres, width=40)
    text_addres_city_id.grid(row=1, column=3)

    label_addres_city_name = Label(frame_addres, text='название:')
    label_addres_city_name.grid(row=2, column=2)
    text_addres_city_name = Entry(frame_addres, width=40)
    text_addres_city_name.grid(row=2, column=3)

    btn = Button(frame_addres, text='Добавить', command=insert_addres_sity)
    btn.grid(row=3, column=2)

    btnOutput = Button(frame_addres, text='Вывести таблицу', command=output_addres_sity)
    btnOutput.grid(row=3, column=3)

    lbl = Label(frame_addres, text="улица")
    lbl.grid(row=0, column=5)

    label_addres_street_id = Label(frame_addres, text='id:')
    label_addres_street_id.grid(row=1, column=4)
    text_addres_street_id = Entry(frame_addres, width=40)
    text_addres_street_id.grid(row=1, column=5)

    label_addres_street_name = Label(frame_addres, text='название:')
    label_addres_street_name.grid(row=2, column=4)
    text_addres_street_name = Entry(frame_addres, width=40)
    text_addres_street_name.grid(row=2, column=5)

    btn = Button(frame_addres, text='Добавить', command=insert_addres_street)
    btn.grid(row=3, column=4)

    btnOutput = Button(frame_addres, text='Вывести таблицу', command=output_addres_street)
    btnOutput.grid(row=3, column=5)

    lbl = Label(frame_addres, text="здание ")
    lbl.grid(row=0, column=7)

    label_addres_bilding_id = Label(frame_addres, text='id:')
    label_addres_bilding_id.grid(row=1, column=6)
    text_addres_bilding_id = Entry(frame_addres, width=40)
    text_addres_bilding_id.grid(row=1, column=7)

    label_addres_bilding_name = Label(frame_addres, text='название:')
    label_addres_bilding_name.grid(row=2, column=6)
    text_addres_bilding_name = Entry(frame_addres, width=40)
    text_addres_bilding_name.grid(row=2, column=7)

    btn = Button(frame_addres, text='Добавить', command=insert_addres_bilding)
    btn.grid(row=3, column=6)

    btnOutput = Button(frame_addres, text='Вывести таблицу', command=output_addres_bilding)
    btnOutput.grid(row=3, column=7)

    lbl = Label(frame_addres, text="адрес ")
    lbl.grid(row=4, column=1)

    label_addres_id = Label(frame_addres, text='id:')
    label_addres_id.grid(row=5, column=0)
    text_addres_id = Entry(frame_addres, width=40)
    text_addres_id.grid(row=5, column=1)

    label_addres_county = Label(frame_addres, text='id страны:')
    label_addres_county.grid(row=6, column=0)
    text_addres_county = Entry(frame_addres, width=40)
    text_addres_county.grid(row=6, column=1)

    label_addres_city = Label(frame_addres, text='id города:')
    label_addres_city.grid(row=7, column=0)
    text_addres_city = Entry(frame_addres, width=40)
    text_addres_city.grid(row=7, column=1)

    label_addres_street = Label(frame_addres, text='id улицы:')
    label_addres_street.grid(row=8, column=0)
    text_addres_street = Entry(frame_addres, width=40)
    text_addres_street.grid(row=8, column=1)

    label_addres_bilding = Label(frame_addres, text='id здания:')
    label_addres_bilding.grid(row=9, column=0)
    text_addres_bilding = Entry(frame_addres, width=40)
    text_addres_bilding.grid(row=9, column=1)

    btn = Button(frame_addres, text='Добавить', command=insert_addres)
    btn.grid(row=10, column=0)

    btnOutput = Button(frame_addres, text='Вывести таблицу', command=output_addres)
    btnOutput.grid(row=10, column=1)

    textOutputAddres = Text(frame_addres, width=200, height=20, font='Consolas 10')
    textOutputAddres.place(x=10, y=300)

    window.mainloop()
