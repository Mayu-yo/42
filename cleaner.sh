#!/bin/bash

echo "ストレージの状況を表示します"
sleep 1

# ディスク使用状況を表示します
df -h -t

echo "容量の大きいファイルを一覧で表示します"
sleep 1

# 最大20個のファイルをサイズ順に表示します
du -k /Users/$USER/* | sort -rn | head -20

# yを入力すると、不要な一時ファイルを削除します。
while true; do
    read -p "不要な一時ファイルを削除します。よろしいですか？(y/n)：" confirm
    case $confirm in
        [Yy]* )
            # Codeのワークスペースストレージとキャッシュを削除します。
            rm -rf /Users/$USER/Library/Application\ Support/Code/User/workspaceStorage
            rm -rf /Users/$USER/Library/Caches
            # 削除が完了しました
            echo "削除が完了しました"
            break
            ;;
        [Nn]* )
            # 処理を中断しました
            echo "処理を中断しました"
            break
            ;;
        * )
            # yかn以外が入力された場合
            echo "yかnを入力してください。"
            ;;
    esac
done
