import requests

url = "https://google-translate113.p.rapidapi.com/api/v1/translator/text"

payload = {
	"from": "auto",
	"to": "en",
	"text": "xin chào"
}
headers = {
	"content-type": "application/x-www-form-urlencoded",
	"X-RapidAPI-Key": "e2bd9123d4msh76904f72fca37ecp1336b9jsnbcb00bf1e915",
	"X-RapidAPI-Host": "google-translate113.p.rapidapi.com"
}

response = requests.post(url, data=payload, headers=headers)

print(response.json())