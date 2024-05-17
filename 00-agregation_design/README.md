# cpp-module-model-example
Este es un ejemplo de un modelo de módulos binarios mediante la implementación de un utilitario traductor multilenguaje.

Este ejemplo intenta resolver problemas de gestión de memoria mediante el uso de RAII

RAII (del inglés resource acquisition is initialization, que podría traducirse como «adquirir recursos es inicializar») es un popular patrón de diseño en varios lenguajes de programación orientados a objetos como C++ y Ada. La técnica fue inventada por Bjarne Stroustrup1​ para reservar y liberar recursos en C++. En este lenguaje, después de que una excepción es lanzada, el único código fuente que con seguridad es ejecutado es el de los destructores de objetos que residen en la pila. Por lo tanto los recursos necesitan ser gestionados con objetos adecuados. Los recursos son adquiridos durante la inicialización, cuando no hay posibilidad de que sean usados antes de estar disponibles, y liberados cuando se destruyen los mismos, algo que es garantizado que suceda incluso cuando se dan errores.

La técnica RAII es vital al escribir código C++ seguro frente a excepciones: para liberar recursos antes de permitir a las excepciones que se propaguen (para evitar fugas de memoria) el desarrollador puede escribir destructores apropiados una sola vez, ahorrándose escribir código de «limpieza» duplicado y disperso por el código fuente entre bloques de manejo de excepciones que pueden ser ejecutados o no.

A diferencia de la recolección de basura, RAII tiene las ventajas de saber cuándo los objetos existen y cuándo no.

Para hacer uso de RAII en este ejemplo nos valemos del uso de Smart Pointers de la STL
