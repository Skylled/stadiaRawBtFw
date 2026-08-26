// 600ff9fe  FUN_600ff9fe  size=54 bytes
// --- callers ---
//   600f367e FUN_600f367e
//   600ae90c FUN_600ae90c
//   600ae4e0 FUN_600ae4e0
//   600ae670 FUN_600ae670
//   600f6be6 FUN_600f6be6
//   600ae7f8 FUN_600ae7f8
//   600f37d2 FUN_600f37d2
//   600aed40 FUN_600aed40
//   600ad710 FUN_600ad710
//   600f622a FUN_600f622a
// --- callees ---
//   600ff986 FUN_600ff986


undefined1 FUN_600ff9fe(int param_1,int param_2)

{
  undefined1 local_9;
  
  local_9 = 0x80;
  if ((param_1 != 0) && (param_2 != 0)) {
    *(undefined2 *)(param_2 + 4) = 0xd;
    local_9 = FUN_600ff986(param_1,param_2);
  }
  return local_9;
}


