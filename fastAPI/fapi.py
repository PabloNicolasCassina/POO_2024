from fastapi import FastAPI, HTTPException
from pydantic import BaseModel
from pymongo import MongoClient

# Configuración de la conexión a MongoDB
mongo_client = MongoClient("mongodb://localhost:27017")
db = mongo_client["Usuarios"]
collection = db["usuarios"]

# Definición del modelo de datos para los usuarios
class User(BaseModel):
    username: str
    password: str

# Inicializar la aplicación FastAPI
app = FastAPI()

# Endpoint para validar usuarios
@app.post("/validate_user/")
async def validate_user(user: User):
    # Buscar el usuario en la base de datos
    db_user = collection.find_one({"username": user.username, "password": user.password})
    if db_user:
        return {"message": "Usuario válido"}
    else:
        raise HTTPException(status_code=401, detail="Credenciales inválidas")
