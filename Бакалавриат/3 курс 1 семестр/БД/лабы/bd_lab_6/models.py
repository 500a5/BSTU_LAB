from peewee import *

db = SqliteDatabase('BD.db')


class BaseModel(Model):
    class Meta:
        database = db


class Country(BaseModel):
    county = CharField(max_length=50)

    @staticmethod
    def get_names():
        return ['id', 'county']


class City(BaseModel):
    city = CharField(max_length=50)

    @staticmethod
    def get_names():
        return ['id', 'city']


class Street(BaseModel):
    street = CharField(max_length=50)

    @staticmethod
    def get_names():
        return ['id', 'street']


class Building(BaseModel):
    building = CharField(max_length=50)

    @staticmethod
    def get_names():
        return ['id', 'building']


class Address(BaseModel):
    country = ForeignKeyField(Country, related_name='address', on_delete='CASCADE')
    city = ForeignKeyField(City, related_name='address', on_delete='CASCADE')
    street = ForeignKeyField(Street, related_name='address', on_delete='CASCADE')
    building = ForeignKeyField(Building, related_name='address', on_delete='CASCADE')

    @staticmethod
    def get_names():
        return ['id', 'country', 'city', 'street', 'building']


class NameProduct(BaseModel):
    name = CharField(max_length=250)

    @staticmethod
    def get_names():
        return ['id', 'neme']


class Product(BaseModel):
    name = ForeignKeyField(NameProduct, related_name='product', on_delete='CASCADE')
    address = ForeignKeyField(Address, related_name='product', on_delete='CASCADE')
    size = IntegerField()
    weight = IntegerField()

    @staticmethod
    def get_names():
        return ['id', 'name', 'address', 'size', 'weight']


class Storage(BaseModel):
    product = ForeignKeyField(Product, related_name='storage', on_delete='CASCADE')
    address = ForeignKeyField(Address, related_name='storage', on_delete='CASCADE')

    @staticmethod
    def get_names():
        return ['id', 'product', 'address ']


class ConsumerContactDetails(BaseModel):
    name = CharField(max_length=50)
    description = CharField(max_length=50)
    email = CharField(max_length=50)
    phone = CharField(max_length=50)

    @staticmethod
    def get_names():
        return ['id', 'name', 'description', 'email', 'phone']


class TypeDelivery(BaseModel):
    type = CharField(max_length=50)

    @staticmethod
    def get_names():
        return ['id', 'type']


class DeliveryOrder(BaseModel):
    product = ForeignKeyField(Product, related_name='delivery_order', on_delete='CASCADE')
    price = IntegerField()
    start_date = DateField()
    end_date = DateField()
    type_delivery = ForeignKeyField(TypeDelivery, related_name='delivery_order', on_delete='CASCADE')

    @staticmethod
    def get_names():
        return ['id', 'product', 'price', 'start_date', 'end_date', 'type_delivery']


class Consumer(BaseModel):
    delivery_order = ForeignKeyField(DeliveryOrder, related_name='consumer', on_delete='CASCADE')
    address = ForeignKeyField(Address, related_name='consumer', on_delete='CASCADE')
    contact_details = ForeignKeyField(ConsumerContactDetails, related_name='consumer', on_delete='CASCADE')

    @staticmethod
    def get_names():
        return ['id', 'delivery_order', 'address', 'contact_details']


class ProviderContactDetails(BaseModel):
    name = CharField(max_length=50)
    description = CharField(max_length=50)
    email = CharField(max_length=50)
    phone = CharField(max_length=50)

    @staticmethod
    def get_names():
        return ['id', 'name', 'description', 'email', 'phone']


class Provider(BaseModel):
    product = ForeignKeyField(Product, related_name='provider', on_delete='CASCADE')
    address = ForeignKeyField(Address, related_name='provider', on_delete='CASCADE')
    contact_details = ForeignKeyField(ProviderContactDetails, related_name='provider', on_delete='CASCADE')

    @staticmethod
    def get_names():
        return ['id', 'product', 'address', 'contact_details']


class TypeTransport(BaseModel):
    type = IntegerField()

    @staticmethod
    def get_names():
        return ['id', 'type']


class TypeSizeTransport(BaseModel):
    size = IntegerField()
    type = ForeignKeyField(TypeTransport, related_name='type_size_transport', on_delete='CASCADE')

    @staticmethod
    def get_names():
        return ['id', 'size', 'type']

class ModelTransport(BaseModel):
    model = CharField(max_length=50)

    @staticmethod
    def get_names():
        return ['id', 'model']

class Transport(BaseModel):
    type_size = ForeignKeyField(TypeSizeTransport, related_name='transport', on_delete='CASCADE')
    model = ForeignKeyField(ModelTransport, related_name='transport', on_delete='CASCADE')

    @staticmethod
    def get_names():
        return ['id', 'type_size', 'model']


class CourierContactDetails(BaseModel):
    name = CharField(max_length=50)
    email = CharField(max_length=50)
    phone = CharField(max_length=50)

    @staticmethod
    def get_names():
        return ['id', 'name', 'email', 'phone']


class Courier(BaseModel):
    transport = ForeignKeyField(Transport, related_name='courier', on_delete='CASCADE')
    location = DoubleField()
    delivery_orders = ForeignKeyField(DeliveryOrder, related_name='courier', on_delete='CASCADE')
    contact_details = ForeignKeyField(CourierContactDetails, related_name='courier', on_delete='CASCADE')

    @staticmethod
    def get_names():
        return ['id', 'transport', 'location', 'delivery_orders', 'contact_details']


class TransportCompanyContactDetails(BaseModel):
    name = CharField(max_length=50)
    description = CharField(max_length=50)
    email = CharField(max_length=50)
    phone = CharField(max_length=50)

    @staticmethod
    def get_names():
        return ['id', 'name', 'description', 'email', 'phone']


class TransportCompany(BaseModel):
    courier = ForeignKeyField(Courier, related_name='transport_company', on_delete='CASCADE')
    delivery_order = ForeignKeyField(DeliveryOrder, related_name='transport_company', on_delete='CASCADE')
    address = ForeignKeyField(Address, related_name='transport_company', on_delete='CASCADE')
    contact_details = ForeignKeyField(TransportCompanyContactDetails, related_name='transport_company', on_delete='CASCADE')

    @staticmethod
    def get_names():
        return ['id', 'courier', 'delivery_order', 'address', 'contact_details']


for m in [Country, City, Street, Building, Address, NameProduct, Product, Storage,
          ConsumerContactDetails, TypeDelivery, DeliveryOrder, Consumer, ProviderContactDetails,
          Provider, TypeTransport, TypeSizeTransport, ModelTransport, Transport,
          CourierContactDetails, Courier, TransportCompanyContactDetails, TransportCompany]:
    if not m.table_exists():
        m.create_table()
