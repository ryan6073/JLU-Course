package util;//规范后端传给前端数据格式

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class DigestUtils {
    public static final String MD5 = "MD5";
    public static final String SHA1 = "SHA-1";
    public static final String SHA256 = "SHA-256";

    public DigestUtils() {
    }

    public static String digest(String mess, String method) {
        try {
            MessageDigest md = MessageDigest.getInstance(method);
            md.update(mess.getBytes());
            byte[] digest = md.digest();
            char[] hexDigits = new char[]{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
            char[] result = new char[digest.length * 2];
            int k = 0;

            for(int i = 0; i < digest.length; ++i) {
                byte byte0 = digest[i];
                result[k++] = hexDigits[byte0 >>> 4 & 15];
                result[k++] = hexDigits[byte0 & 15];
            }

            return new String(result);
        } catch (NoSuchAlgorithmException var9) {
            var9.printStackTrace();
            return null;
        }
    }

    public static String sha256Digest(String mess) {
        return digest(mess, "SHA-256");
    }
}
