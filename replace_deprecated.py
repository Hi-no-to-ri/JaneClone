import os
import re

# 置換ルールの定義
REPLACEMENTS = [
    # libcurl
    (r'\bCURLOPT_HTTPPOST\b', 'CURLOPT_MIMEPOST'),
    (r'\bCURLOPT_PROGRESSFUNCTION\b', 'CURLOPT_XFERINFOFUNCTION'),
    (r'\bcurl_formadd\b', 'curl_mime_init'),
    (r'\bCURLFORM_PTRNAME\b', 'curl_mime_name'),
    (r'\bCURLFORM_FILE\b', 'curl_mime_filedata'),
    (r'\bCURLFORM_CONTENTTYPE\b', 'curl_mime_type'),
    (r'\bCURLFORM_PTRCONTENTS\b', 'curl_mime_data'),
    (r'\bcurl_formfree\b', 'curl_mime_free'),

    # wxFont (簡易対応: wxFont(12, ...) → wxFont(wxFontInfo(12))
    (r'wxFont\s*\(\s*([0-9]+)\s*,\s*wxDEFAULT\s*,\s*wxNORMAL\s*,\s*wxNORMAL\s*,\s*0\s*,\s*wxT\(""\)\s*\)',
     r'wxFont(wxFontInfo(\1).Family(wxFONTFAMILY_DEFAULT).Style(wxFONTSTYLE_NORMAL).Weight(wxFONTWEIGHT_NORMAL))'),

    (r'wxFont\s*\(\s*([0-9]+)\s*,\s*wxDEFAULT\s*,\s*wxNORMAL\s*,\s*wxNORMAL\s*,\s*0\s*,\s*wxT\(""\)\s*,\s*wxFONTENCODING_DEFAULT\s*\)',
     r'wxFont(wxFontInfo(\1).Family(wxFONTFAMILY_DEFAULT).Style(wxFONTSTYLE_NORMAL).Weight(wxFONTWEIGHT_NORMAL))'),
]

def replace_in_file(filepath):
    with open(filepath, 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()
    original_content = content
    for pattern, repl in REPLACEMENTS:
        content = re.sub(pattern, repl, content)
    if content != original_content:
        with open(filepath, 'w', encoding='utf-8') as f:
            f.write(content)
        print(f"Updated: {filepath}")

def walk_and_replace(root='.'):
    for dirpath, _, filenames in os.walk(root):
        for filename in filenames:
            if filename.endswith('.cpp') or filename.endswith('.hpp'):
                filepath = os.path.join(dirpath, filename)
                replace_in_file(filepath)

if __name__ == '__main__':
    walk_and_replace('.')
