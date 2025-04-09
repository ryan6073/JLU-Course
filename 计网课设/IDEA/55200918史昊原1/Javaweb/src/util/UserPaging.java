package util;

import model.User;
import java.util.List;

public class UserPaging {
    private int pageSize;
    private int totalRecord;
    private int totalPage;
    private int pageNum;
    private List<User> data;
    private boolean hasData;
    private int recordNum;

    public UserPaging(int totalRecord, int totalPage, int pageSize, int pageNum, List<User> data) {
        this.totalRecord = totalRecord;
        this.totalPage = totalPage;
        this.pageSize = pageSize;
        this.pageNum = pageNum;
        this.data = data;
        this.hasData = data.size() > 0;
        this.recordNum = data.size();
    }

    public int getPageSize() {
        return this.pageSize;
    }

    public int getTotalRecord() {
        return this.totalRecord;
    }

    public int getTotalPage() {
        return this.totalPage;
    }

    public List<User> getData() {
        return this.data;
    }

    public boolean isHasData() {
        return this.hasData;
    }

    public int getRecordNum() {
        return this.recordNum;
    }

    public int getPageNum() {
        return this.pageNum;
    }
}
