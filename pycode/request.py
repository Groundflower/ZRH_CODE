import requests
import re


headers = {
    "cookie":"_tea_utm_cache_10000007=undefined; recente=%5B%7B%22vod_name%22%3A%22%E8%B4%9E%E6%93%8D%E9%94%81%E5%AF%B8%E6%AD%A2%E6%8C%91%E6%88%98%22%2C%22vod_url%22%3A%22https%3A%2F%2Fx12ygj33q2vlxym.com%3A58010%2Findex.php%2Fvod%2Fplay%2Fid%2F174175%2Fsid%2F1%2Fnid%2F1.html%22%2C%22vod_part%22%3A%22%E7%AC%AC1%E9%9B%86%22%7D%2C%7B%22vod_name%22%3A%22%E7%AC%AC%E4%B8%80%E8%A7%86%E8%A7%92-%E5%B7%A8%E4%B9%B3%E6%AF%8D%E7%8B%97%E8%B6%85%22%2C%22vod_url%22%3A%22https%3A%2F%2Fx12ygj33q2vlxym.com%3A58010%2Findex.php%2Fvod%2Fplay%2Fid%2F174250%2Fsid%2F1%2Fnid%2F1.html%22%2C%22vod_part%22%3A%22%E7%AC%AC1%E9%9B%86%22%7D%2C%7B%22vod_name%22%3A%22%E7%AC%AC%E4%B8%80%E8%A7%86%E8%A7%92-%E6%AF%8F%E5%BD%93%E6%88%91%E4%BB%AC%E7%8B%AC%22%2C%22vod_url%22%3A%22https%3A%2F%2Fx12ygj33q2vlxym.com%3A58010%2Findex.php%2Fvod%2Fplay%2Fid%2F174248%2Fsid%2F1%2Fnid%2F1.html%22%2C%22vod_part%22%3A%22%E7%AC%AC1%E9%9B%86%22%7D%2C%7B%22vod_name%22%3A%22%E7%AC%AC%E4%B8%80%E8%A7%86%E8%A7%92-%E7%9C%8B%E5%88%B0%E5%A9%8A%E5%A7%90%E7%9A%84%22%2C%22vod_url%22%3A%22https%3A%2F%2Fx12ygj33q2vlxym.com%3A58010%2Findex.php%2Fvod%2Fplay%2Fid%2F174249%2Fsid%2F1%2Fnid%2F1.html%22%2C%22vod_part%22%3A%22%E7%AC%AC1%E9%9B%86%22%7D%2C%7B%22vod_name%22%3A%22%E5%9B%BD%E4%BA%A7AV%E5%89%A7%E6%83%85-%E6%8B%89%E9%9D%A2%E5%BA%97%22%2C%22vod_url%22%3A%22https%3A%2F%2Fx12ygj33q2vlxym.com%3A58010%2Findex.php%2Fvod%2Fplay%2Fid%2F169945%2Fsid%2F1%2Fnid%2F1.html%22%2C%22vod_part%22%3A%22%E7%AC%AC1%E9%9B%86%22%7D%2C%7B%22vod_name%22%3A%22%E5%A4%A7%E5%AD%A6%E5%9F%8E%E9%99%84%E8%BF%91%E8%AE%A4%E8%AF%86%E7%9A%84%E6%B0%94%E8%B3%8D%22%2C%22vod_url%22%3A%22https%3A%2F%2Fx12ygj33q2vlxym.com%3A58010%2Findex.php%2Fvod%2Fplay%2Fid%2F111887%2Fsid%2F1%2Fnid%2F1.html%22%2C%22vod_part%22%3A%22%E7%AC%AC1%E9%9B%86%22%7D%2C%7B%22vod_name%22%3A%22%E6%9E%81%E5%93%81%E7%BD%91%E7%BA%A2%E5%A5%B3%E7%A5%9E%E9%B9%BF%E5%B0%91%E5%A5%B3%E5%9C%A8%22%2C%22vod_url%22%3A%22https%3A%2F%2Fx12ygj33q2vlxym.com%3A58010%2Findex.php%2Fvod%2Fplay%2Fid%2F113226%2Fsid%2F1%2Fnid%2F1.html%22%2C%22vod_part%22%3A%22%E7%AC%AC1%E9%9B%86%22%7D%2C%7B%22vod_name%22%3A%22%E6%8E%A8%E7%89%B9%E4%BA%BA%E6%B0%94%E9%BB%91%E6%9A%97%E8%90%9D%E8%8E%89CA%22%2C%22vod_url%22%3A%22https%3A%2F%2Fx12ygj33q2vlxym.com%3A58010%2Findex.php%2Fvod%2Fplay%2Fid%2F130024%2Fsid%2F1%2Fnid%2F1.html%22%2C%22vod_part%22%3A%22%E7%AC%AC1%E9%9B%86%22%7D%5D",
    "user-agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/142.0.0.0 Safari/537.36 Edg/142.0.0.0"
}

Turl = 'https://x12ygj33q2vlxym.com:58010/index.php/vod/play/id/174252/sid/1/nid/1.html'

response = requests.get(url=Turl, headers=headers)
html = response.text

title = re.findall('content="(.*?)" /><meta', html)
ri=re.findall('player_data":".*?}</script>', html)
print(ri)