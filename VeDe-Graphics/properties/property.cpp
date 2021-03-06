#include "property.h"

const int &gx::Property::toInt() const
{
    if(m_type == PROP_INT)
    {
        return m_value.i;
    }
    else
    {
        throw new IncorrectPropertyType;
    }
}

const double &gx::Property::toDouble() const
{
    if(m_type == PROP_DOUBLE)
    {
        return m_value.d;
    }
    else
    {
        throw new IncorrectPropertyType;
    }
}

const QString &gx::Property::toString() const
{
    if(m_type == PROP_STRING)
    {
        return *m_value.s;
    }
    else
    {
        throw new IncorrectPropertyType;
    }
}

const gx::Color &gx::Property::toColor() const
{
    if(m_type == PROP_COLOR)
    {
        return *m_value.c;
    }
    else
    {
        throw new IncorrectPropertyType;
    }
}

int &gx::Property::toInt()
{
    if(m_type == PROP_INT)
    {
        return m_value.i;
    }
    else
    {
        throw new IncorrectPropertyType;
    }
}

double &gx::Property::toDouble()
{
    if(m_type == PROP_DOUBLE)
    {
        return m_value.d;
    }
    else
    {
        throw new IncorrectPropertyType;
    }
}

QString &gx::Property::toString()
{
    if(m_type == PROP_STRING)
    {
        return *m_value.s;
    }
    else
    {
        throw new IncorrectPropertyType;
    }
}

gx::Color &gx::Property::toColor()
{
    if(m_type == PROP_COLOR)
    {
        return *m_value.c;
    }
    else
    {
        throw new IncorrectPropertyType;
    }
}

void gx::Property::setInt(int value)
{
    if(m_type == PROP_INT)
    {
        m_value.i = value;
    }
    else
    {
        throw new IncorrectPropertyType;
    }
}

void gx::Property::setDouble(double value)
{
    if(m_type == PROP_DOUBLE)
    {
        m_value.d = value;
    }
    else
    {
        throw new IncorrectPropertyType;
    }
}

void gx::Property::setString(const QString &value)
{
    if(m_type == PROP_STRING)
    {
        delete m_value.s; //TODO : check
        m_value.s = new QString(value);
    }
    else
    {
        throw new IncorrectPropertyType;
    }
}

void gx::Property::setColor(const gx::Color &value)
{
    if(m_type == PROP_COLOR)
    {
        *m_value.c = value;
    }
    else
    {
        throw new IncorrectPropertyType;
    }
}

gx::Property *gx::Property::createProperty(const QString& name, gx::PropertyType type)
{
    Property *prop = new Property(type, name);

    prop->resetToDefault();

    return prop;
}

gx::Property::Property(const gx::Property &other)
{
    this->m_type = other.m_type;
    this->m_name = other.m_name;

    switch(m_type)
    {
        case PROP_INT:
            m_value.i = other.m_value.i;
            break;
        case PROP_DOUBLE:
            m_value.d = other.m_value.d;
            break;
        case PROP_STRING:
            m_value.s = new QString(*other.m_value.s);
            break;
        case PROP_COLOR:
            m_value.c = new Color(*other.m_value.c);
            break;
    }
}

gx::Property::~Property()
{
    switch(m_type)
    {
        case PROP_STRING:
            delete m_value.s;
            break;
        case PROP_COLOR:
            delete m_value.c;
            break;
        default:;
    }
}

void gx::Property::resetToDefault()
{
    switch(m_type)
    {
        case PROP_INT:
            m_value.i = 0;
            break;
        case PROP_DOUBLE:
            m_value.d = 0.0f;
            break;
        case PROP_STRING:
            m_value.s = new QString;
            break;
        case PROP_COLOR:
            m_value.c = new Color(0,0,0);
            break;
    }
}

gx::Property::Property(PropertyType type, QString name)
    :m_type(type), m_name(name)
{}

gx::PropertyType gx::Property::getType() const
{
    return m_type;
}

QString gx::Property::name() const
{
    return m_name;
}

void gx::Property::setName(const QString &name)
{
    m_name = name;
}
