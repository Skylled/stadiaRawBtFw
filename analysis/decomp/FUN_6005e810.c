// 6005e810  FUN_6005e810  size=100 bytes
// --- callers ---
//   6005e884 FUN_6005e884
// --- callees ---
//   600cc450 FUN_600cc450
//   600d46fe FUN_600d46fe
//   6010138c FUN_6010138c
//   6005d844 trigger_bug_report__6005d844
//   600d45e8 FUN_600d45e8
//   60101a80 FUN_60101a80
//   6010135a FUN_6010135a
//   60101aa4 FUN_60101aa4


void FUN_6005e810(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 local_4c4;
  undefined1 auStack_4c0 [28];
  undefined1 auStack_4a4 [272];
  undefined1 auStack_394 [272];
  undefined1 auStack_284 [632];
  
  FUN_600d46fe(auStack_4a4);
  uVar1 = FUN_60101a80(auStack_4a4);
  FUN_600cc450(uVar1,DAT_6005e874,param_1);
  trigger_bug_report__6005d844();
  FUN_600d46fe(auStack_394);
  local_4c4 = DAT_6005e878;
  FUN_600d45e8(auStack_284,&local_4c4,1);
  FUN_6010135a(auStack_4c0,DAT_6005e87c,0,0,auStack_394,auStack_284);
  uVar1 = FUN_60101a80(auStack_394);
  FUN_60101aa4(uVar1,DAT_6005e880,auStack_4a4);
  FUN_6010138c(auStack_4c0,auStack_394);
  return;
}


