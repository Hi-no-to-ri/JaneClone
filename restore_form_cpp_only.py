import os
import re

# Define the target file for partial restoration
target_file = os.path.join('curlpp', 'src', 'curlpp', 'Form.cpp')

# Define the specific replacements to restore deprecated curl form API usage
partial_restore_replacements = [
    (r'\bcurl_mime_free\b', 'curl_formfree'),
    (r'\bcurl_mime_init\b', 'curl_formadd'),
    (r'\bcurl_mime_name\b', 'CURLFORM_PTRNAME'),
    (r'\bcurl_mime_filedata\b', 'CURLFORM_FILE'),
    (r'\bcurl_mime_type\b', 'CURLFORM_CONTENTTYPE'),
    (r'\bcurl_mime_data\b', 'CURLFORM_PTRCONTENTS'),
]

def restore_form_cpp_only(filepath):
    with open(filepath, 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()
    original_content = content
    for pattern, repl in partial_restore_replacements:
        content = re.sub(pattern, repl, content)
    if content != original_content:
        with open(filepath, 'w', encoding='utf-8') as f:
            f.write(content)
        print(f"Restored deprecated curl form API usage in: {filepath}")
    else:
        print(f"No changes made to: {filepath}")

if __name__ == '__main__':
    if os.path.exists(target_file):
        restore_form_cpp_only(target_file)
    else:
        print(f"Target file not found: {target_file}")
