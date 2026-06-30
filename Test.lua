-- 简易本地文件统计小工具
local function scan_folder(target_path)
    local handle = io.popen(string.format('dir "%s" /b 2>nul', target_path))
    if not handle then
        print("读取目录失败")
        return
    end
    print("==== 当前目录文件清单 ====")
    for filename in handle:lines() do
        print(filename)
    end
    handle:close()
end

local function count_script_files()
    local lua_count = 0
    local cmd = io.popen('dir /s /b *.lua 2>nul')
    if cmd then
        for file in cmd:lines() do
            lua_count = lua_count + 1
        end
        cmd:close()
    end
    print("\n==== 脚本文件统计 ====")
    print("项目内Lua脚本总数：", lua_count)
end

-- 程序入口
print("本地文件扫描工具已启动")
scan_folder(".")
count_script_files()

