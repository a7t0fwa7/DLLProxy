import pefile
import argparse

def print_exported_functions(path, proxy_dll_name):
    pe = pefile.PE(path)
    for entry in pe.DIRECTORY_ENTRY_EXPORT.symbols:
        if entry.name == None:
            print("Anonymous function detected!")
            break

        name = entry.name.decode('utf-8')
        ordinal = entry.ordinal
        exported_function = f'#pragma comment(linker,"/export:{name}={proxy_dll_name}.{name},@{ordinal}")'
        print(exported_function)

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("-t", "--target", type=str, help="Proxied dll path")
    parser.add_argument("-n", "--name", type=str, help=" New name for proxied dll")
    
    args = parser.parse_args()
    if args.target and args.name:
        print_exported_functions(args.target, args.name)
    else:
        parser.print_help()
