// 600d8c7a  FUN_600d8c7a  size=224 bytes
// --- callers ---
//   600d7ad6 FUN_600d7ad6
// --- callees ---
//   6013d0b0 thunk_EXT_FUN_00001ea4
//   600d8c1a FUN_600d8c1a
//   600d8c3e FUN_600d8c3e


void FUN_600d8c7a(int param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  ushort *puVar5;
  char *pcVar6;
  ushort *puVar7;
  char local_30 [4];
  char local_2c;
  ushort local_2b;
  
  local_30[0] = '\x10';
  local_30[1] = '0';
  iVar4 = param_1 + 8;
  local_30[2] = 0x50;
  FUN_600d8c3e();
  cVar1 = FUN_600d8c1a(iVar4,0x70,*param_2 << 4 | param_2[3] << 6 | param_2[2] | param_2[1] << 2,200
                      );
  if ((cVar1 == '\0') && (cVar1 = FUN_600d8c1a(iVar4,1,0x15,200), cVar1 == '\0')) {
    puVar5 = (ushort *)(param_2 + 2);
    pcVar6 = local_30;
    do {
      cVar1 = '\0';
      puVar7 = puVar5;
      do {
        puVar7 = puVar7 + 1;
        local_2c = *pcVar6 + cVar1;
        local_2b = *puVar7 >> 8 | *puVar7 << 8;
        cVar2 = thunk_EXT_FUN_00001ea4
                          (*(undefined4 *)(param_1 + 8),*(undefined1 *)(param_1 + 0xc),&local_2c,3,0
                           ,0,200);
        if (cVar2 != '\0') {
          return;
        }
        cVar1 = cVar1 + '\x02';
      } while (cVar1 != ' ');
      puVar5 = puVar5 + 0x10;
      pcVar6 = pcVar6 + 1;
    } while ((ushort *)(param_2 + 0x62) != puVar5);
    cVar1 = FUN_600d8c1a(iVar4,1,0x2a,200);
    if (cVar1 == '\0') {
      if (*(char *)(param_1 + 4) == '\0') {
        uVar3 = 0x6a;
      }
      else {
        uVar3 = 0xea;
      }
      FUN_600d8c1a(iVar4,0,uVar3,200);
    }
  }
  return;
}


