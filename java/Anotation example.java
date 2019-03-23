
//***********************Anotation***********************
@Retention(RetentionPolicy.RUNTIME)
@Target(ElementType.FIELD)
public @interface JsonField {
    public String value() default "";
}

//*****************Class that use anotation
public class Car {
    @JsonField("manufacturer")
    private final String make;
    @JsonField
    private final String model;
    private final String year;
    public Car(String make, String model, String year) {
        this.make = make;
        this.model = model;
        this.year = year;
    }
    public String getMake() {
        return make;
    }
    public String getModel() {
        return model;
    }
    public String getYear() {
        return year;
    }
    @Override
    public String toString() {
        return year + " " + make + " " + model;
    }
}

//*****************Process Annotation*******************
public class JsonSerializer {
    public String serialize(Object object) throws JsonSerializeException {
        try {
            Class<?> objectClass = requireNonNull(object).getClass();
            Map<String, String> jsonElements = new HashMap<>();
            for (Field field: objectClass.getDeclaredFields()) {
                field.setAccessible(true);
                if (field.isAnnotationPresent(JsonField.class)) {
                    jsonElements.put(getSerializedKey(field), (String) field.get(object));
                }
            }
            System.out.println(toJsonString(jsonElements));
            return toJsonString(jsonElements);
        }
        catch (IllegalAccessException e) {
            throw new JsonSerializeException(e.getMessage());
        }
    }
    private String toJsonString(Map<String, String> jsonMap) {
        String elementsString = jsonMap.entrySet()
                .stream()
                .map(entry -> "\""  + entry.getKey() + "\":\"" + entry.getValue() + "\"")
                .collect(joining(","));
        return "{" + elementsString + "}";
    }
    private static String getSerializedKey(Field field) {
        String annotationValue = field.getAnnotation(JsonField.class).value();
        if (annotationValue.isEmpty()) {
            return field.getName();
        }
        else {
            return annotationValue;
        }
    }
}

//************************Test Annotation*********************
Car car = new Car("Ford", "F150", "2018");
JsonSerializer serializer = new JsonSerializer();
serializer.serialize(car);